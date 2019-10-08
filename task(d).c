#include "msp.h"

int main(void) {

    volatile uint32_t x; //flag for seatbelt buckle
    volatile uint32_t y; //flag for car door latch
    
    //left proximity sensor - P1.1
    P1->SEL1 &= ~BIT1;
    P1->SEL0 &= ~BIT1;
    P1->DIR &= ~BIT1;
    P1->REN |= BIT1;
    P1->OUT |= BIT1;         

    //right proximity sensor - P1.4
    P1->SEL1 &= ~BIT4;
    P1->SEL0 &= ~BIT4;
    P1->DIR &= ~BIT4;
    P1->REN |= BIT4;
    P1->OUT |= BIT4;        

    //forward - P1.0 
    P1->SEL1 &= ~BIT0;
    P1->SEL0 &= ~BIT0;
    P1->DIR |= BIT0;

    //backward - P2.0
    P2->SEL1 &= ~BIT0;
    P2->SEL0 &= ~BIT0;
    P2->DIR |= BIT0;

    //left  - P2.1
    P2->SEL1 &= ~BIT1;
    P2->SEL0 &= ~BIT1;
    P2->DIR |= BIT1;

    //right  - P2.2
    P2->SEL1 &= ~BIT2;
    P2->SEL0 &= ~BIT2;
    P2->DIR |= BIT2;


    while (1) {
        
        if (P1->IN & BIT1)
        {
            P1->OUT = BIT0;
            x = 0;
        }

        else
        {
             P1->OUT &= ~BIT0;
             x = 1;
        }


        if (P1->IN & BIT4)
        {
            P2->OUT = BIT0;
            y = 0;
        }

        else
        {
             P2->OUT &= ~BIT0;
             y = 1;
        }


        if (x==0 && y==0)
        {
            P1->OUT &= ~BIT0;
            P2->OUT =  BIT0;
            P2->OUT =  BIT1;
            P2->OUT =  BIT2;
        }
        
        if (x==0 && y==1)
        {
            P1->OUT =  BIT0;
            P2->OUT =  BIT0;
            P2->OUT&= ~BIT1;
            P2->OUT =  BIT2;
        }

        if (x==1 && y==0)
        {
            P1->OUT =  BIT0;
            P2->OUT =  BIT0;
            P2->OUT =  BIT1;
            P2->OUT&= ~BIT2;
        }

        if (x==1 && y==1)
        {
            P1->OUT =  BIT0;
            P2->OUT&= ~BIT0;
            P2->OUT =  BIT1;
            P2->OUT =  BIT2;
        }
    }
}