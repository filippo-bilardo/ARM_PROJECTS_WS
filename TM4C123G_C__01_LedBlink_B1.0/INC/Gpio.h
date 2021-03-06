//==========================================================================================
// Filename:
// Description:
// Author:	Filippo Bilardo
//
// Ver    	Date        Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	07.11.15 	Initial version
//
//==========================================================================================
#ifndef _GPIO_H_
#define _GPIO_H_

//------------------------------------------------------------------------------------------
//=== Includes =============================================================================
//------------------------------------------------------------------------------------------
//#include <stdint.h>
typedef unsigned int   uint32_t;
typedef unsigned char  uint8_t;

//------------------------------------------------------------------------------------------
//=== Global function prototypes ===========================================================
//------------------------------------------------------------------------------------------
void GpioInitPortF();
void GpioSet(uint32_t Port, uint8_t Pin, uint8_t Stato);
void GpioWrite(uint32_t Port, uint8_t Pins, uint8_t Level);
uint8_t GpioRead(uint32_t Port, uint8_t Pins);

//------------------------------------------------------------------------------------------
//=== Macro ================================================================================
//------------------------------------------------------------------------------------------
// Macro per impostare l'indirizzo completo dei registri
#define SET_REGISTER(BaseAddress, Offest) 	(*((volatile unsigned long*)(BaseAddress+Offest)))

//------------------------------------------------------------------------------------------
//=== Global constants =====================================================================
//------------------------------------------------------------------------------------------
// GpioSet defines
#define OUTPUT 1
#define INPUT 0

// GpioWrite defines
#define HIGH 1
#define LOW 0

#define SYSCTL_RCGC2_R      (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_PORTF		0x20

//
// Define pin mapping.
// LAUNCH PAD BASE HARDWARE
//
#define RED_LED_PIN		0x02	//J3.10 PF1 29 - U1CTS SSI1Tx - T0CCP1 - C1o TD1
#define BLUE_LED_PIN	0x04	//J4.01 PF2 30 - - SSI1Clk - T1CCP0 - - TRD0
#define GREEN_LED_PIN	0x08	//J4.02 PF3 31 - - SSI1Fss CAN0Tx T1CCP1 - - TRCLK
#define SW_LEFT_PIN		0x10	//J4.10 PF4 05 - - - - T2CCP0 - - -
#define SW_RIGHT_PIN	0x01	//J2.04 PF0 28 - U1RTS SSI1Rx CAN0Rx T0CCP0 NMI C0o -
#define LED0			0x02	//J3.10 PF1 29 - U1CTS SSI1Tx - T0CCP1 - C1o TD1
#define LED1			0x04	//J4.01 PF2 30 - - SSI1Clk - T1CCP0 - - TRD0
#define LED2			0x08	//J4.02 PF3 31 - - SSI1Fss CAN0Tx T1CCP1 - - TRCLK

// Offset dei vari registri
typedef enum {
	GPIODATA = 0x3FC,
	GPIODIR = 0x400,
	GPIOIS = 0x404,
	GPIOIBE = 0x408,
	GPIOIEV = 0x40C,
	GPIOIM = 0x410,
	GPIORIS = 0x414,
	GPIOMIS = 0x418,
	GPIOICR = 0x41C,
	GPIOAFSEL = 0x420,
	GPIODR2R = 0x500,
	GPIODR4R = 0x504,
	GPIODR8R = 0x508,
	GPIOODR = 0x50C,
	GPIOPUR = 0x510,
	GPIOPDR = 0x514,
	GPIOSLR = 0x518,
	GPIODEN = 0x51C,
	GPIOLOCK = 0x520,
	GPIOCR = 0x524,
	GPIOAMSEL = 0x528,
	GPIOPCTL = 0x52C
} RegOffset;

// Indirizzo di base delle varie porte
typedef enum {
	PORTA = 0x40004000,
	PORTB = 0x40005000,
	PORTC = 0x40006000,
	PORTD = 0x40007000,
	PORTE = 0x40024000,
	PORTF = 0x40025000,
	PORTG = 0x40026000,
	PORTH = 0x40027000,
	PORTI = 0x4003D000
} RegBaseAddr;

//------------------------------------------------------------------------------------------
#endif //_GPIO_H_
