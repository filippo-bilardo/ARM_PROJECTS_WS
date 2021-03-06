//==========================================================================================
//
// Project: LedBlink
// Date:    13.11.15
// Author:  Filippo Bilardo
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  Lampeggio di un led presente nella scheda utilizzando un software delay
//
// Ver      Date        Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// A1.0     13.11.15    Versione iniziale
//                      Il firmware � realizzato con il numero minimo indispensabile
//                      di line di codice
// A1.1     13.11.15    Strutturazione del codice utilizzando funzioni e utilizzo di
//                      costanti
//
//==========================================================================================
//-----------------------------------------------------------------------------------------
//=== Includes =============================================================================
//------------------------------------------------------------------------------------------
//#include <stdint.h>
typedef unsigned int   uint32_t;

//------------------------------------------------------------------------------------------
//=== Costanti =============================================================================
//------------------------------------------------------------------------------------------
#define GPIO_PORTF_DATA_R   (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R    (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R  (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DEN_R    (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R  (*((volatile unsigned long *)0x40025528))
#define SYSCTL_RCGC2_R      (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF 	0x00000020  // PortF Clock Gating Control

// Hardware Abstraction Layer
#define LED0_PIN			0x04	//J4.02 PF3 31 - - SSI1Fss CAN0Tx T1CCP1 - - TRCLK
#define LED0_SYSCTL_PORT    SYSCTL_RCGC2_GPIOF
#define LED0_PORT_DATA_R    GPIO_PORTF_DATA_R
#define LED0_PORT_DIR_R     GPIO_PORTF_DIR_R
#define LED0_PORT_AFSEL_R   GPIO_PORTF_AFSEL_R
#define LED0_PORT_DEN_R     GPIO_PORTF_DEN_R
#define LED0_PORT_AMSEL_R   GPIO_PORTF_AMSEL_R
#define LED0_PORT_DATA_R    GPIO_PORTF_DATA_R

//------------------------------------------------------------------------------------------
//=== Prototipi delle funzioni =============================================================
//------------------------------------------------------------------------------------------
void SoftDelay(uint32_t delay_ms);
void LedInit(void);
void Led0On(void);
void Led0Off(void);

//------------------------------------------------------------------------------------------
//=== Main =================================================================================
//------------------------------------------------------------------------------------------
int main(void)
{
	// Inizializzazioni
	LedInit();

	// Autodiagnostica

	// Ciclo infinito
	for(;;)
	{
		Led0On();
		SoftDelay(500);
		Led0Off();
		SoftDelay(500);
	}
}

//------------------------------------------------------------------------------------------
//=== Routines =============================================================================
//------------------------------------------------------------------------------------------
void SoftDelay(uint32_t delay_ms)
{
	int i;
	int coefficiente=2000;

	for(i=0; i< coefficiente*delay_ms ; ++i)
	{
		asm("nop");
	}
}

//------------------------------------------------------------------------------------------
void LedInit(void)
{
	// LED 0
	#ifdef LED0_PIN
	SYSCTL_RCGC2_R |= LED0_SYSCTL_PORT; // activate port
	LED0_PORT_DIR_R |= LED0_PIN; 		// make pin out
	LED0_PORT_AFSEL_R &= ~LED0_PIN;		// disable alt functionality
	LED0_PORT_DEN_R |= LED0_PIN; 		// enable digital I/O
	LED0_PORT_AMSEL_R &= ~LED0_PIN;		// disable analog functionality
	#endif
}

//------------------------------------------------------------------------------------------
void Led0On(void)
{
	LED0_PORT_DATA_R |= LED0_PIN;
}

//------------------------------------------------------------------------------------------
void Led0Off(void)
{
	LED0_PORT_DATA_R &= ~LED0_PIN;
}

