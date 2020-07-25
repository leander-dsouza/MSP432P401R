#include "msp.h"


void main(void)
{

   WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;      // stop watch dog timer

   P1->DIR = 0x00000001;
   P1->REN = BIT1|BIT4;
   P1->OUT = BIT1|BIT4;

   while (1)

   {
       if ((P1->IN & BIT1 ==0x00) || (P1->IN & BIT4 ==0x00))
       { P1->OUT |=BIT0;}
       else
       { P1->OUT &= ~BIT0;}
   }

}


