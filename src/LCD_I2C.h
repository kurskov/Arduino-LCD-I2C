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

#include "Wire.h"

/*
Command codes
from manual LCDscreen_JHD659.pdf (page 13)
*/

// Screen clear
#define _DK_LCD_SCREEN_CLEAR 0x01

// Cursor return
#define _DK_LCD_CURSOR_RETURN 0x02

// Input set
#define _DK_LCD_INPUT_SET 0x04
#define _DK_LCD_CURSOR_MOVE_RIGHT 0x02
#define _DK_LCD_CURSOR_MOVE_LEFT 0x00
#define _DK_LCD_CURSOR_MOVE 0x01
#define _DK_LCD_CURSOR_DONT_MOVE 0x00

// Display switch
#define _DK_LCD_DISPLAY_SWITCH 0x08
#define _DK_LCD_DISPLAY_ON 0x04
#define _DK_LCD_DISPLAY_OFF 0x00
#define _DK_LCD_CURSOR_ON 0x02
#define _DK_LCD_CURSOR_OFF 0x00
#define _DK_LCD_CURSOR_BLINK_ON 0x01
#define _DK_LCD_CURSOR_BLINK_OFF 0x00

// Shift
#define _DK_LCD_SHIFT 0x16
#define _DK_LCD_SHIFT_DISPLAY 0x08
#define _DK_LCD_SHIFT_CURSOR 0x00
#define _DK_LCD_SHIFT_RIGHT 0x04
#define _DK_LCD_SHIFT_LEFT 0x00

// Function set
#define _DK_LCD_FUNCTION_SET 0x32
#define _DK_LCD_8_BITS_MODE 0x16
#define _DK_LCD_4_BITS_MODE 0x00
#define _DK_LCD_2_LINES_MODE 0x08
#define _DK_LCD_1_LINE_MODE 0x00
#define _DK_LCD_FONT_5X10 0x04
#define _DK_LCD_FONT_5X7 0x00

class LCD_I2C {
    public:
        // Constructor
        // Usually for address used next values: 0x26, 0x27 or 0x3F. 
        LCD_I2C(uint8_t addr, uint8_t cols, uint8_t rows);

    private:
        uint8_t _addr;
        uint8_t _cols;
        uint8_t _rows;
}

#endif
