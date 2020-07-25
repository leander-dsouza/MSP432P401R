#include "msp.h"

int main(void)
{
    volatile uint32_t i;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;   // Stop watchdog timer

                        // The following code toggles P2 port
    P2->DIR |= 0xff;                             // Configure P2 as output

    while(1)
    {
        P2->OUT ^= 0xff;                         // Toggle P2
        for(i=10000; i>0; i--);                  // Delay
    }
}
