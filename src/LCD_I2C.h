/*
    LCD I2C
    
    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
    GitHub: https://github.com/kurskov/Arduino-LCD-I2C
    Version: 1.0.0

    MIT license
*/

#ifndef _DK_LCD_I2C_h
#define _DK_LCD_I2C_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

class LCD_I2C {
    public:
        LCD_I2C(uint8_t addr, uint8_t cols, uint8_t rows);

    private:
        uint8_t _addr;
        uint8_t _cols;
        uint8_t _rows;
}

#endif
