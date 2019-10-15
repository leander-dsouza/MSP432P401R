#include "msp.h"
void main(void)
{
    volatile uint32_t i;
    volatile uint32_t j=6;
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    P1->DIR |= BIT0;                             // Configure P1.0 as output
    P2->DIR |= 0xff;

	while(j>0)
	{


	    P2->OUT = 0x01;
	    for(i=100000; i>0; i--);
            P2->OUT = 0x02;
            for(i=100000; i>0; i--);
            P2->OUT = 0x04;
            for(i=100000; i>0; i--);
            P1->OUT = 0x01;                         // Toggle P1.0
            for(i=100000; i>0; i--);
            P1->OUT = 0x00;
            j--;
	}

	P2->OUT = 0x00;
}
