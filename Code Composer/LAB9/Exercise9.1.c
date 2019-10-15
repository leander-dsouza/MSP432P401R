
#include "msp.h"

int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW |WDT_A_CTL_HOLD;

     //Configure GPIO
    P1->DIR |= BIT0;
    P1->OUT &= ~BIT0;

     //Timer32 set up in periodic mode, 32-bit, no pre-scale
TIMER32_1->CONTROL = TIMER32_CONTROL_SIZE |TIMER32_CONTROL_MODE;

     //Load Timer32 counter with period = 0x20000
    TIMER32_1->LOAD= 0x2DC6BF;

     //Enable the Timer32 interrupt in NVIC
    __enable_irq();
    NVIC->ISER[0] = 1 << ((T32_INT1_IRQn) & 31);

     Enable sleep on exit from ISR
    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

     Start Timer32 with interrupt enabled
TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE |TIMER32_CONTROL_IE;

     //Enter LPM0;
    __sleep();

     //For the debugger when halt is asserted. This is only needed for debug mode
    __no_operation();
}

void T32_INT1_IRQHandler(void)
{
    TIMER32_1->INTCLR |= BIT0;       //Clear Timer32 interrupt flag
    P1->OUT ^= BIT0;                              //Toggle P1.0 LED
}
