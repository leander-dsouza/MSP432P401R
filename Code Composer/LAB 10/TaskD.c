#include "msp.h"

int main(void) {

    volatile uint32_t x;
    volatile uint32_t y;

    //left proximity sensor - P1.1

    P1->DIR &= ~BIT1;
    P1->REN |= BIT1;
    P1->OUT |= BIT1;

    //right proximity sensor - P1.4

    P1->DIR &= ~BIT4;
    P1->REN |= BIT4;
    P1->OUT |= BIT4;


    //forward - P1.0

    P1->DIR |= BIT0;

    //backward - P2.0

    P2->DIR |= BIT0;

    //left  - P2.1

    P2->DIR |= BIT1;

    //right  - P2.2
    P2->DIR |= BIT2;


    while (1) {

        if ((P1->IN & BIT1)==BIT1)
        {
            x = 0;
        }

        if (!((P1->IN & BIT1)==BIT1))
        {

             x = 1;
        }


        if ((P1->IN & BIT4)==BIT4)
        {

            y = 0;
        }

        if (!((P1->IN & BIT4)==BIT4))
        {

             y = 1;
        }


        if (x==0 && y==0)
        {
            P1->OUT |= BIT0;
            P2->OUT&= ~BIT0;
            P2->OUT&= ~BIT1;
            P2->OUT&= ~BIT2;
        }

        if (x==0 && y==1)
        {
            P1->OUT&= ~BIT0;
            P2->OUT&= ~BIT0;
            P2->OUT |= BIT1;
            P2->OUT&= ~BIT2;
        }

        if (x==1 && y==0)
        {
            P1->OUT&= ~BIT0;
            P2->OUT&= ~BIT0;
            P2->OUT&= ~BIT1;
            P2->OUT |= BIT2;
        }

        if (x==1 && y==1)
        {
            P1->OUT&= ~BIT0;
            P2->OUT |= BIT0;
            P2->OUT&= ~BIT1;
            P2->OUT&= ~BIT2;
        }
    }
}
