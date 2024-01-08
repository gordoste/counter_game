/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18325
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SPI_CS2 aliases
#define SPI_CS2_TRIS                 TRISAbits.TRISA2
#define SPI_CS2_LAT                  LATAbits.LATA2
#define SPI_CS2_PORT                 PORTAbits.RA2
#define SPI_CS2_WPU                  WPUAbits.WPUA2
#define SPI_CS2_OD                   ODCONAbits.ODCA2
#define SPI_CS2_ANS                  ANSELAbits.ANSA2
#define SPI_CS2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SPI_CS2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SPI_CS2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SPI_CS2_GetValue()           PORTAbits.RA2
#define SPI_CS2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SPI_CS2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SPI_CS2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SPI_CS2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SPI_CS2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SPI_CS2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SPI_CS2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SPI_CS2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SPI_DAT aliases
#define SPI_DAT_TRIS                 TRISCbits.TRISC0
#define SPI_DAT_LAT                  LATCbits.LATC0
#define SPI_DAT_PORT                 PORTCbits.RC0
#define SPI_DAT_WPU                  WPUCbits.WPUC0
#define SPI_DAT_OD                   ODCONCbits.ODCC0
#define SPI_DAT_ANS                  ANSELCbits.ANSC0
#define SPI_DAT_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SPI_DAT_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SPI_DAT_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SPI_DAT_GetValue()           PORTCbits.RC0
#define SPI_DAT_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SPI_DAT_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SPI_DAT_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SPI_DAT_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SPI_DAT_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SPI_DAT_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SPI_DAT_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SPI_DAT_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SPI_CLK aliases
#define SPI_CLK_TRIS                 TRISCbits.TRISC1
#define SPI_CLK_LAT                  LATCbits.LATC1
#define SPI_CLK_PORT                 PORTCbits.RC1
#define SPI_CLK_WPU                  WPUCbits.WPUC1
#define SPI_CLK_OD                   ODCONCbits.ODCC1
#define SPI_CLK_ANS                  ANSELCbits.ANSC1
#define SPI_CLK_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SPI_CLK_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SPI_CLK_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SPI_CLK_GetValue()           PORTCbits.RC1
#define SPI_CLK_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SPI_CLK_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SPI_CLK_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SPI_CLK_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SPI_CLK_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SPI_CLK_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SPI_CLK_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SPI_CLK_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SPI_CS1 aliases
#define SPI_CS1_TRIS                 TRISCbits.TRISC2
#define SPI_CS1_LAT                  LATCbits.LATC2
#define SPI_CS1_PORT                 PORTCbits.RC2
#define SPI_CS1_WPU                  WPUCbits.WPUC2
#define SPI_CS1_OD                   ODCONCbits.ODCC2
#define SPI_CS1_ANS                  ANSELCbits.ANSC2
#define SPI_CS1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SPI_CS1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SPI_CS1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SPI_CS1_GetValue()           PORTCbits.RC2
#define SPI_CS1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SPI_CS1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SPI_CS1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SPI_CS1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SPI_CS1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SPI_CS1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SPI_CS1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SPI_CS1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set BTN1 aliases
#define BTN1_TRIS                 TRISCbits.TRISC3
#define BTN1_LAT                  LATCbits.LATC3
#define BTN1_PORT                 PORTCbits.RC3
#define BTN1_WPU                  WPUCbits.WPUC3
#define BTN1_OD                   ODCONCbits.ODCC3
#define BTN1_ANS                  ANSELCbits.ANSC3
#define BTN1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define BTN1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define BTN1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define BTN1_GetValue()           PORTCbits.RC3
#define BTN1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define BTN1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define BTN1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define BTN1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define BTN1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define BTN1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define BTN1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define BTN1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set BTN0 aliases
#define BTN0_TRIS                 TRISCbits.TRISC4
#define BTN0_LAT                  LATCbits.LATC4
#define BTN0_PORT                 PORTCbits.RC4
#define BTN0_WPU                  WPUCbits.WPUC4
#define BTN0_OD                   ODCONCbits.ODCC4
#define BTN0_ANS                  ANSELCbits.ANSC4
#define BTN0_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define BTN0_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define BTN0_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define BTN0_GetValue()           PORTCbits.RC4
#define BTN0_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define BTN0_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define BTN0_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define BTN0_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define BTN0_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define BTN0_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define BTN0_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define BTN0_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/