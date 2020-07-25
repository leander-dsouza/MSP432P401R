#include "msp.h"

uint32_t ClockFrequency = 48e6;
int x, y, z;

void delay(unsigned long ulCount)
{
  __asm (  "pdloop:  subs    r0, #1\n"      "    bne    pdloop\n");
}

void Clock_Delay1ms(uint32_t n)
{
while(n)
  {
    delay(ClockFrequency/48e3);
    n--;
  }
}


void main(void)
{

   WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;      // stop watchdog timer
    CS->KEY = CS_KEY_VAL;
    CS->CTL0 = CS_CTL0_DCOEN | CS_CTL0_DCORSEL_1;
    CS->CTL1 = CS_CTL1_SELM_3;
    CS->KEY = 0;
   P2->DIR |= BIT1;

   P1->DIR &= ~BIT1;
   P1->REN = BIT1;

   P1->DIR &= ~BIT1;
   P1->IES = BIT1;
   P1->IFG = 0;
   P1->IE = BIT1;

  NVIC-> ISER[1] = 1<< (PORT1_IRQn & 31);
  __enable_irq();
}

  void PORT1_IRQHandler(void)
  {
      if (P1->IFG & BIT1)
      {
          Clock_Delay1ms(1000);
          P2->OUT^= BIT1;

      }
      P1->IFG&= ~BIT1;

}
