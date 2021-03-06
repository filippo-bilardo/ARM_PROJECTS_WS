//==========================================================================================
//
// Project:	LedBlink
// Date:	13.11.15
// Author:	Filippo Bilardo
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  Lampeggio di un led presente nella scheda utilizzando un software delay
//
// Ver		Date		Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// A1.0		13.11.15	Versione iniziale
//						Il firmware � realizzato utilizzando il numero minimo indispensabile
//						di line di codice
//
//==========================================================================================
//------------------------------------------------------------------------------------------
//=== Costanti =============================================================================
//------------------------------------------------------------------------------------------
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//------------------------------------------------------------------------------------------
//=== Main =================================================================================
//------------------------------------------------------------------------------------------
int main(void)
{
	int i;
	int coefficiente=2000;
	int delay_ms=500;

	// Inizializzazione del pin 3 della porta F come output
	SYSCTL_RCGC2_R |=  0x00000020; 	// PortF Clock Gating Control 	// activate port
	GPIO_PORTF_DIR_R |= 0x08;		// J4.02 PF3 	// make pin out
	GPIO_PORTF_AFSEL_R &= ~0x08;	// disable alt functionality
	GPIO_PORTF_DEN_R |= 0x08; 		// enable digital I/O
	GPIO_PORTF_AMSEL_R &= ~0x08;	// disable analog functionality

	// Autodiagnostica

	// Ciclo infinito
	for(;;)
	{
		GPIO_PORTF_DATA_R |= 0x08;
		for(i=0; i< coefficiente*delay_ms ; ++i) {asm("  nop");}
		GPIO_PORTF_DATA_R &= ~0x08;
		for(i=0; i< coefficiente*delay_ms ; ++i) {asm("  nop");}
	}
}
