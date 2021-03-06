//==================================================================================================
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//	    | |     | |_| |
//	www.|_|     |_____/-labs.blogspot.it
//
// Filename:    hwconfig.h
// Description: Hardware abstraction layer for TM4C123 (LM4F120)
//    
// Open Source Licensing 
//
// This program is free software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation, either version 3 
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.  
// If not, see <http://www.gnu.org/licenses/>.
//
// Author:	Filippo Bilardo
//
// Ver		Date   		Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	12.11.12	Initial version
//
//==================================================================================================

#ifndef __HWCONFIG_LAUNCHPAD_H__
#define __HWCONFIG_LAUNCHPAD_H__

//--------------------------------------------------------------------------------------------------
//=== Global constants =============================================================================
//--------------------------------------------------------------------------------------------------
//
// Define pin mapping.
// LAUNCH PAD BASE HARDWARE
//
#define RED_LED_PIN				0x02	//J3.10 PF1 29 - U1CTS SSI1Tx - T0CCP1 - C1o TD1
#define BLUE_LED_PIN			0x04	//J4.01 PF2 30 - - SSI1Clk - T1CCP0 - - TRD0
#define GREEN_LED_PIN			0x08	//J4.02 PF3 31 - - SSI1Fss CAN0Tx T1CCP1 - - TRCLK
#define LED0_PIN				0x02	//J3.10 PF1 29 - U1CTS SSI1Tx - T0CCP1 - C1o TD1
#define LED1_PIN				0x04	//J4.01 PF2 30 - - SSI1Clk - T1CCP0 - - TRD0
#define LED2_PIN				0x08	//J4.02 PF3 31 - - SSI1Fss CAN0Tx T1CCP1 - - TRCLK
#define SW_LEFT_PIN				0x10	//J4.10 PF4 05 - - - - T2CCP0 - - -
#define SW_RIGHT_PIN			0x01	//J2.04 PF0 28 - U1RTS SSI1Rx CAN0Rx T0CCP0 NMI C0o -
#define SW0_PIN					0x10	//J4.10 PF4 05 - - - - T2CCP0 - - -
#define SW1_PIN					0x01	//J2.04 PF0 28 - U1RTS SSI1Rx CAN0Rx T0CCP0 NMI C0o -
#define LED0					0x02	//J3.10 PF1 29 - U1CTS SSI1Tx - T0CCP1 - C1o TD1
#define LED1					0x04	//J4.01 PF2 30 - - SSI1Clk - T1CCP0 - - TRD0
#define LED2					0x08	//J4.02 PF3 31 - - SSI1Fss CAN0Tx T1CCP1 - - TRCLK
#define LED3

// Pulsante digitale 1
#define PULS_D1					SW_LEFT_PIN
#define PULS_D1_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define PULS_D1_PORT_DIR_R		GPIO_PORTF_DIR_R
#define PULS_D1_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define PULS_D1_PORT_DEN_R		GPIO_PORTF_DEN_R
#define PULS_D1_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define PULS_D1_PORT_PUR_R		GPIO_PORTF_PUR_R
#define PULS_D1_PORT_PDR_R		GPIO_PORTF_PDR_R
#define PULS_D1_PORT_DATA_R		GPIO_PORTF_DATA_R

#define PULS_D2					SW_RIGHT_PIN
#define PULS_D2_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define PULS_D2_PORT_DIR_R		GPIO_PORTF_DIR_R
#define PULS_D2_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define PULS_D2_PORT_DEN_R		GPIO_PORTF_DEN_R
#define PULS_D2_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define PULS_D2_PORT_PUR_R		GPIO_PORTF_PUR_R
#define PULS_D2_PORT_PDR_R		GPIO_PORTF_PDR_R
#define PULS_D2_PORT_LOCK_R		GPIO_PORTF_LOCK_R
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
#define PULS_D2_PORT_DATA_R		GPIO_PORTF_DATA_R

#define LED1_SYSCTL_PERIPH		SYSCTL_PERIPH_GPIOF
#define LED1_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOF
#define LED1_PORTF_BASE			GPIO_PORTF_BASE
#define LED1_PORT_DIR_R			GPIO_PORTF_DIR_R
#define LED1_PORT_AFSEL_R		GPIO_PORTF_AFSEL_R
#define LED1_PORT_DEN_R			GPIO_PORTF_DEN_R
#define LED1_PORT_AMSEL_R		GPIO_PORTF_AMSEL_R
#define LED1_PORT_DATA_R		GPIO_PORTF_DATA_R

#define RED_LED_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define RED_LED_PORT_DIR_R		GPIO_PORTF_DIR_R
#define RED_LED_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define RED_LED_PORT_DEN_R		GPIO_PORTF_DEN_R
#define RED_LED_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define RED_LED_PORT_DATA_R		GPIO_PORTF_DATA_R

#define BLUE_LED_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define BLUE_LED_PORT_DIR_R		GPIO_PORTF_DIR_R
#define BLUE_LED_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define BLUE_LED_PORT_DEN_R		GPIO_PORTF_DEN_R
#define BLUE_LED_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define BLUE_LED_PORT_DATA_R	GPIO_PORTF_DATA_R

#define GREEN_LED_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOF
#define GREEN_LED_PORT_DIR_R	GPIO_PORTF_DIR_R
#define GREEN_LED_PORT_AFSEL_R	GPIO_PORTF_AFSEL_R
#define GREEN_LED_PORT_DEN_R	GPIO_PORTF_DEN_R
#define GREEN_LED_PORT_AMSEL_R	GPIO_PORTF_AMSEL_R
#define GREEN_LED_PORT_DATA_R	GPIO_PORTF_DATA_R

////--------------------------------------------------------------------------------------------------
#endif //  __HWCONFIG_LAUNCHPAD_H__
