#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state
    P9DIR |= BIT7;
    P1OUT |= BIT0;                          // Set P1.0 to output direction
    P9OUT |= BIT7;
    P5DIR &= ~(BIT5+BIT6);                  // Set P5.5 and .6 to Inputs (buttons)

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    P5REN |= BIT5 + BIT6;                   //Enable pull up resistor
    P5OUT |= BIT5 + BIT6;

        while(1)
        {
            if(!(P5IN&BIT5)) //button 5.5 blinks red LED
            {
            P1OUT |= BIT0;
            }
            else
            {
             P1OUT &= ~(BIT0);
            }

            if(!(P5IN&BIT6)) //button 5.6 blinks green LED
            {
            P9OUT |= BIT7;
            }
            else
            {
            P9OUT &= ~(BIT7);
            }
       }
    }

