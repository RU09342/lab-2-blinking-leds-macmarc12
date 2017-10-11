#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P1DIR &= ~(BIT1);                  // Set P1.1 to Input

    P1REN |= BIT1;                   //Enable pull up resistor
    P1OUT |= BIT1;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
        {
            if(!(P1IN&BIT1)) //button 1.1 blinks LED
            {
            P1OUT |= BIT0;
            }
            else
            {
             P1OUT &= ~(BIT0);
            }
        }

}
