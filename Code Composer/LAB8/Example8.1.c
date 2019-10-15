#include "msp.h"

void main(void)
{

   WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;   // stop watch dog timer
   CS->KEY = CS_KEY_VAL;                         //enable clock set
   CS->CTL0 = CS_CTL0_DCOEN | CS_CTL0_DCORSEL_1; //?
   CS->CTL1 = CS_CTL1_SELM_3;                    //?
   CS->KEY = 0;                                  //disable clock set

   P2->DIR |= BIT1;

   P1->DIR &= ~BIT1;  //P1.1 switch
   P1->REN = BIT1;    //pull up active low


   P1->IES = BIT1;    //falling edge
   P1->IFG = 0;       //set flag to 0
   P1->IE = BIT1;     //enable interrupt

  NVIC-> ISER[1] = 1<< (PORT1_IRQn & 31);       //?
  __enable_irq();
}

  void PORT1_IRQHandler(void)
  {
      if (P1->IFG & BIT1)   //if flag is raised
      {
          P2->OUT^= BIT1;   //toggle
      }
      P1->IFG&= ~BIT1;      //reset

}
