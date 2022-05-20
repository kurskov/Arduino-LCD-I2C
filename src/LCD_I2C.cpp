/*
    See LCD_I2C.h for all information.

    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
*/

#include "LCD_I2C.h"


// Constructor & initializaision

LCD_I2C::LCD_I2C(uint8_t addr) {
    _addr = addr;
}

LCD_I2C::init(uint8_t cols, uint8_t rows, uint8_t font) {
    _cols = cols;
    _rows = rows;
    
    // INITIALIZATION SEQUENCE (4-bit interface)
    // Wait time > 15 ms after VDD > 4.5V
    delay(50);

    // Function set
    _command = 0 | _DK_LCD_4_BITS_MODE | _DK_LCD_1_LINE_MODE | _DK_LCD_FONT_5X7;

    if (_rows == 0) {
        if (font != 0) {
            _command |= _DK_LCD_FONT_5X10;
        }
    } else {
        _command |= _DK_LCD_2_LINES_MODE;
    }
}


// Lowlevel connection

#if defined(ARDUINO) && ARDUINO >= 100
    #define sendI2C(args) Wire.write(args)
#else
    #define sendI2C(args) Wire.send(args)
#endif

LCD_I2C::transmission(uint8_t data) {
    Wire.beginTransmission(_addr);
    sendI2C((int)data);
    Wire.endTransmission();
}
