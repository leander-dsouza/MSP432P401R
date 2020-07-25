#include "msp.h"
int i=0;
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    P2->DIR |= 0xff;

    while(1)
    {
        P2->OUT ^= 0xff;
        for (i=1000; i>0; i--);

    }
}

