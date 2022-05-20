/*
    See LCD_I2C.h for all information.

    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
*/

#include "LCD_I2C.h"


// Constructor

LCD_I2C::LCD_I2C(uint8_t addr, uint8_t cols, uint8_t rows) {
    _addr = addr;
    _cols = cols;
    _rows = rows;
}
