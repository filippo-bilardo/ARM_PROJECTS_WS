//==========================================================================================
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//      | |     | |_| |
//  www.|_|     |_____/-labs.blogspot.it
//
// Led driver: Funzioni per l'utilizzo dei led presenti nella scheda
//    
// Open Source Licensing 
// This program is free software: you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software Foundation, either
// version 3 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this
// program. If not, see <http://www.gnu.org/licenses/>.
//
// Author:  Filippo Bilardo
//
// Ver    Date       Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0  27.11.13   Initial version
// 1.0.1  29.10.14   adeguamento commenti
// 1.1.0  15.11.15   Utilizzo delle librerie TI
//
//==========================================================================================
#ifndef _LED
#define _LED

//------------------------------------------------------------------------------------------
//=== Includes =============================================================================
//------------------------------------------------------------------------------------------
//Include librerie standard del compilatore
#include <stdint.h>          // Libreria per tipi aritmetici C99

//------------------------------------------------------------------------------------------
//=== Constants ============================================================================
//------------------------------------------------------------------------------------------
//#define LED0
//#define LED1
//#define LED2
//#define LED3

//------------------------------------------------------------------------------------------
//=== Function prototypes ==================================================================
//------------------------------------------------------------------------------------------
void LedInit(void);
void LedOn(void);
void LedOff(void);
void LedBlink(uint8_t val, uint16_t cont, uint16_t delay);
void LedTest(void);
void LedTest2(void);
void LedHex(uint8_t val);
void Led0On(void);
void Led0Off(void);
void Led0Toggle(void);
void Led1On(void);
void Led1Off(void);
void Led1Toggle(void);
void Led2On(void);
void Led2Off(void);
void Led2Toggle(void);
void Led3On(void);
void Led3Off(void);
void Led3Toggle(void);
void LedRedOn(void);
void LedRedOff(void);
void LedRedToggle(void);
void LedBlueOn(void);
void LedBlueOff(void);
void LedBlueToggle(void);
void LedGreenOn(void);
void LedGreenOff(void);
void LedGreenToggle(void);
void LedWhiteOn(void);
void LedWhiteOff(void);
void LedWhiteToggle(void);

//------------------------------------------------------------------------------------------
#endif //_LED
