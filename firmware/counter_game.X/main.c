/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18325
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"

#define BOUNCE_NUM  100

#define DECODE      0xFF
#define NODECODE    0x00

// MAX 7219 registers
#define NO_OP       0x00
#define ROW0        0x01
#define ROW1        0x02
#define ROW2        0x03
#define ROW3        0x04
#define ROW4        0x05
#define ROW5        0x06
#define ROW6        0x07
#define ROW7        0x08
#define DECODEMODE  0x09    // DECODE, NODECODE
#define INTENSITY   0x0A	// 0-9
#define SCANLIMIT   0x0B    // register accepts 0 to 7
#define SHUTD       0x0C	// 0-1
#define TEST        0x0F	// 0-1

#define WINNER_CHAR_INFO_ADD    0x0040
#define LOSER_CHAR_INFO_ADD     0x0050
#define WINNER_DATA_ADD 0x0400
#define LOSER_DATA_ADD  0x0500

uint8_t winnerCharInfo[] = {5, 3, 4, 4, 4, 4, 1, 1, 1, 0};
uint8_t winnerCharData[] = {
    0b00111111, // W
    0b01000000,
    0b00111100,
    0b01000000,
    0b00111111,
    0b01000100, // i
    0b01111101,
    0b01000000,
    0b01111100, // n
    0b00000100,
    0b00000100,
    0b01111000,
    0b01111100, // n
    0b00000100,
    0b00000100,
    0b01111000,
    0b00111000, // e
    0b01010100,
    0b01010100,
    0b00011000,
    0b01111100, // r
    0b00001000,
    0b00000100,
    0b00000100,
    0b01011111, // !
    0b01011111, // !
    0b01011111 // !
};

uint8_t loserCharInfo[] = {4, 4, 4, 4, 4, 1, 1, 1, 0};
uint8_t loserCharData[] = {
    0b01111111, // L
    0b01000000,
    0b01000000,
    0b01000000,
    0b00111000, // o
    0b01000100,
    0b01000100,
    0b00111000,
    0b01001000, // s
    0b01010100,
    0b01010100,
    0b00100100,
    0b00111000, // e
    0b01010100,
    0b01010100,
    0b00011000,
    0b01111100, // r
    0b00001000,
    0b00000100,
    0b00000100,
    0b01011111, // !
    0b01011111, // !
    0b01011111 // !
};

uint8_t disp_data[2][8]; // buffers for 8x8 LED matrix displays

void display_send(uint8_t display_num, uint8_t reg, uint8_t data);
void display_setRow(uint8_t display_num, uint8_t row, uint8_t cols);

void display_clear(uint8_t display_num) {
    for (uint8_t i = 0; i <= 7; i++) {
        display_setRow(display_num, i, 0);
    }
}

void display_init(uint8_t display_num) {
    display_send(display_num, TEST, 0);
    display_send(display_num, SCANLIMIT, 7);
    display_send(display_num, DECODEMODE, NODECODE);
    display_send(display_num, INTENSITY, 2);
    display_clear(display_num);
    display_send(display_num, SHUTD, 1);
}

void display_send(uint8_t display_num, uint8_t reg, uint8_t data) {
    SPI_CLK_SetLow();
    // Assert CS#
    if (display_num == 0) {
        SPI_CS1_SetLow();
        SPI_CS2_SetHigh();
    }
    if (display_num == 1) {
        SPI_CS1_SetHigh();
        SPI_CS2_SetLow();
    }
    __delay_us(10); // CS settle time
    uint16_t d = (reg << 8) | data; // High byte is address, low byte is data (see data sheet)
    for (uint8_t i = 0; i < 16; i++) {
        // Starting from MSB, write the bit value
        if (d & (0x8000 >> i)) {
            SPI_DAT_SetHigh();
        } else {
            SPI_DAT_SetLow();
        }
        __delay_us(10); // Data setup time
        // Cycle the clock
        SPI_CLK_SetHigh();
        __delay_us(10); // Min clock pulse width
        SPI_CLK_SetLow();
        __delay_us(10);
    }
    // Deassert CS#
    if (display_num == 0) {
        SPI_CS1_SetHigh();
    }
    if (display_num == 1) {
        SPI_CS2_SetHigh();
    }
}

void display_setRow(uint8_t display_num, uint8_t row, uint8_t cols) {
    disp_data[display_num][row] = cols;
    display_send(display_num, row + 1, cols);
}

void display_setLed(uint8_t display_num, uint8_t row, uint8_t col, bool state) {
    uint8_t d = 0x80 >> col;
    display_setRow(display_num, row, state ? disp_data[display_num][row] | d : disp_data[display_num][row] & ~d);
}

void display_updateRow(uint8_t display_num, uint8_t row) {
    display_send(display_num, row + 1, disp_data[display_num][row]);
}

void display_update(uint8_t display_num) {
    for (uint8_t i = 0; i <= 7; i++) display_updateRow(display_num, i);
}

void scrollIntoBuffer(uint8_t *dispBuf, uint8_t newByte) {
    dispBuf[0] = dispBuf[1];
    dispBuf[1] = dispBuf[2];
    dispBuf[2] = dispBuf[3];
    dispBuf[3] = dispBuf[4];
    dispBuf[4] = dispBuf[5];
    dispBuf[5] = dispBuf[6];
    dispBuf[6] = dispBuf[7];
    dispBuf[7] = newByte;
}

void loadingAnim(bool clearBefore, bool clearAfter) {
    if (clearBefore) {
        display_clear(0);
        display_clear(1);
    }
    uint8_t dir = 0;
    uint8_t curX = 3;
    uint8_t curY = 3;
    bool done = false;
    display_setLed(0, curX, curY, true);
    display_setLed(1, curX, curY, true);
    display_update(0);
    while (!done) {
        switch (dir) {
            case 0:
                curX++;
                if (curX > 7) done = true;
                if (!(disp_data[0][curX] & (0x80 >> (curY + 1)))) dir = 1;
                break;
            case 1:
                curY++;
                if (curY > 7) done = true;
                if (!(disp_data[0][curX - 1] & (0x80 >> curY))) dir = 2;
                break;
            case 2:
                if (curX == 0) done = true;
                curX--;
                if (!(disp_data[0][curX] & (0x80 >> (curY - 1)))) dir = 3;
                break;
            case 3:
                if (curY == 0) done = true;
                curY--;
                if (!(disp_data[0][curX + 1] & (0x80 >> curY))) dir = 0;
                break;
        }
        display_setLed(0, curX, curY, true);
        display_setLed(1, curX, curY, true);
        display_update(0);
        display_update(1);
        __delay_ms(20);
    }
    if (clearAfter) {
        display_clear(0);
        display_clear(1);
    }
}

void showWinnerLoserText(uint8_t winnerNum) {
    loadingAnim(true, true);
    uint8_t loserNum = 1 - winnerNum;

    uint8_t winnerChIdx = 0;
    uint8_t winnerDatIdx = 0;
    uint8_t loserChIdx = 0;
    uint8_t loserDatIdx = 0;

    uint8_t letter_colsW = winnerCharInfo[winnerChIdx++];
    uint8_t letter_colsL = loserCharInfo[loserChIdx++];

    bool wTextDone = false;
    bool lTextDone = false;
    uint8_t wScrollOut = 0; // Number of loops since last bit of text
    uint8_t lScrollOut = 0; // Number of loops since last bit of text

    while (wScrollOut < 8 || lScrollOut < 8) {
        if (!wTextDone) {
            if (letter_colsW > 0) {
                scrollIntoBuffer(disp_data[winnerNum], winnerCharData[winnerDatIdx++]);
                letter_colsW--;
            } else {
                scrollIntoBuffer(disp_data[winnerNum], 0);
                letter_colsW = winnerCharInfo[winnerChIdx++];
                if (letter_colsW == 0) wTextDone = true;
            }
        } else {
            scrollIntoBuffer(disp_data[winnerNum], 0);
            wScrollOut++;
        }
        if (!lTextDone) {
            if (letter_colsL > 0) {
                scrollIntoBuffer(disp_data[loserNum], loserCharData[loserDatIdx++]);
                letter_colsL--;
            } else {
                scrollIntoBuffer(disp_data[loserNum], 0);
                letter_colsL = loserCharInfo[loserChIdx++];
                if (letter_colsL == 0) lTextDone = true;
            }
        } else {

            scrollIntoBuffer(disp_data[loserNum], 0);
            lScrollOut++;
        }
        display_update(0);
        display_update(1);
        __delay_ms(100);
    }
}

/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    display_init(0);
    display_init(1);
    uint8_t c0 = 0;
    uint8_t c1 = 0;
    uint8_t btn0_low = 0;
    uint8_t btn0_high = 0;
    bool btn0_press_handled = false;
    uint8_t btn1_low = 0;
    uint8_t btn1_high = 0;
    bool btn1_press_handled = false;
    display_clear(0);
    display_clear(1);

    while (1) {
        if (!BTN0_GetValue()) { // LOW = pressed
            btn0_high = 0;
            btn0_low++;
            if (btn0_low > BOUNCE_NUM) {
                if (!btn0_press_handled) {
                    display_setLed(0, c0 / 8, c0 % 8, true);
                    c0++;
                    if (c0 == 64) {
                        display_clear(0);
                        display_clear(1);
                        showWinnerLoserText(0);
                        c0 = 0;
                        c1 = 0;
                    }
                    btn0_press_handled = true;
                }
            }
        } else {
            btn0_low = 0;
            btn0_high++;
            if (btn0_high > BOUNCE_NUM) {
                btn0_press_handled = false;
            }
        }
        if (!BTN1_GetValue()) { // LOW = pressed
            btn1_high = 0;
            btn1_low++;
            if (btn1_low > BOUNCE_NUM) {
                if (!btn1_press_handled) {
                    display_setLed(1, c1 / 8, c1 % 8, true);
                    c1++;
                    if (c1 == 64) {
                        display_clear(0);
                        display_clear(1);
                        showWinnerLoserText(1);
                        c0 = 0;
                        c1 = 0;
                    }
                    btn1_press_handled = true;
                }
            }
        } else {
            btn1_low = 0;
            btn1_high++;
            if (btn1_high > BOUNCE_NUM) {
                btn1_press_handled = false;
            }
        }
    }
}
/**
 End of File
 */