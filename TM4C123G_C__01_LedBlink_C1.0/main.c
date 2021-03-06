//==========================================================================================
//
// Project:	LedBlink
// Date:	13.11.15
// Author:	Filippo Bilardo
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  Lampeggio di un led presente nella scheda utilizzando un delay
//
// Ver		Date		Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// C1.0		13.11.15	Versione iniziale
//						Il firmware � realizzato utilizzando le librerie fornite dalla TI
//
//==========================================================================================
//------------------------------------------------------------------------------------------
//=== Includes =============================================================================
//------------------------------------------------------------------------------------------
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"

//==========================================================================================
//
// The error routine that is called if the driver library encounters an error.
//
//==========================================================================================
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

//------------------------------------------------------------------------------------------
//=== Main =================================================================================
//------------------------------------------------------------------------------------------
void main(void)
{
    //
    // Enable the GPIO module.
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    ROM_SysCtlDelay(1);

    //
    // Configure PF3 as an output.
    //
    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

    //
    // Loop forever.
    //
    while(1)
    {
        //
        // Set the GPIO high.
        //
        ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);

        //
        // Delay for a while.
        //
        ROM_SysCtlDelay(1000000);

        //
        // Set the GPIO low.
        //
        ROM_GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);

        //
        // Delay for a while.
        //
        ROM_SysCtlDelay(1000000);
    }
}
