#include "msp.h"
uint32_t ClockFrequency = 12e6;

void delay(unsigned long ulCount)
{
  __asm (  "pdloop:  subs    r0, #1\n"      "    bne    pdloop\n");
}

void Clock_Delay1ms(uint32_t n)
{
    while(n)
    {
        delay(ClockFrequency/12e3);   // 1 msec, tuned at 48 MHz
        n--;
    }
}
int main(void)
{
 volatile uint32_t i;
 WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;   // Stop watchdog timer
  P2->DIR |= 0xff;

    while(1)
    {
        P2->OUT = 0x01;
        Clock_Delay1ms(2000);
        P2->OUT = 0x00;

        P2->OUT = 0x02;
        Clock_Delay1ms(2000);
        P2->OUT = 0x00;

        P2->OUT = 0x04;
        Clock_Delay1ms(2000);
        P2->OUT = 0x00;
    }
}


