#include "msp.h"
#include <stdint.h>

int main(void)
{
    volatile uint32_t i;

    WDT_A->CTL = WDT_A_CTL_PW |WDT_A_CTL_HOLD;
    P1->DIR |= BIT0;
    P1->OUT &= ~BIT0;

    // Timer32 set up in one-shot, free run, 32-bit, no pre-scale
    TIMER32_1->CONTROL = TIMER32_CONTROL_SIZE | TIMER32_CONTROL_ONESHOT;

    // Load Timer32 Counter with initial value
    TIMER32_1->LOAD= 0xFFFFFF;

    // Enalbe the Timer32 interrupt in NVIC

    __enable_irq();
    NVIC->ISER[0] = 1 << ((T32_INT1_IRQn) & 31);

    // Start Timer32 and enable interrupt
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE |
            TIMER32_CONTROL_IE;

    // Disable sleep on exit from ISR
    SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;

    // Enter LPM0 and wait for the timer interrupt to wake-up
    __sleep();
    __no_operation();

    // Timer interrupt wakes-up
    while (1)
    {
        P1->OUT ^= BIT0;                    // Toggle P1.0 LED
        for (i = 100000; i > 0; i--);       // Delay
    }
}

void T32_INT1_IRQHandler(void)
{
    TIMER32_1->INTCLR |= BIT0;              // Clear Timer32 interrupt flag

    // Disable the timer and interrupt
    TIMER32_1->CONTROL &= ~(TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE);
}
