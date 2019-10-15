#include "msp.h"
uint32_t ClockFrequencyA = 12e6;
uint32_t ClockFrequencyB = 48e6;

void delay(unsigned long ulCount)
{
  __asm (  "pdloop:  subs    r0, #1\n"      "    bne    pdloop\n");
}

void Clock_Delay1msA(uint32_t n)
{
    while(n)
    {
        delay(ClockFrequencyA/12000);   // 1 msec, tuned at 12 MHz
        n--;
    }
}
void Clock_Delay1msB(uint32_t n)
{

    while(n)
    {
        delay(ClockFrequencyB/48000);   // 1 msec, tuned at 48 MHz
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
        Clock_Delay1msA(1000);
        P2->OUT = 0x00;

        P2->OUT = 0x02;
        Clock_Delay1msB(1000);
        P2->OUT = 0x00;
    }
}


