#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P2OUT &= ~BIT0;
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P2DIR |= BIT0;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    int x, y;
    while(1)
    {
        if(x>=10000)
        {
            P1OUT ^= BIT0;                      // Toggle LED
            x= 0;
        }
        if(y>=20000)
        {
            P2OUT ^= BIT0;
            y=0;
        }
       x++;
       y++;
    }
}
