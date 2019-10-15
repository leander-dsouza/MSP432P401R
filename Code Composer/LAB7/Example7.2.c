#include "msp.h"
uint32_t ClockFrequency = 48000000;
int x, y, z;

void delay(unsigned long ulCount)
{
  __asm (  "pdloop:  subs    r0, #1\n"      "    bne    pdloop\n");
}

void Clock_Delay1ms(uint32_t n)
{
while(n)
  {
    delay(ClockFrequency/9600);   // 1 msec, tuned at 48 MHz
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
        P2->OUT ^= 0xff;
        Clock_Delay1ms(100);
    }
}


