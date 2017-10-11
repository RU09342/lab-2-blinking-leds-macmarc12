#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1DIR &= ~(BIT3);                  // Set P1.3 to Input

  P1REN |= BIT3;                   //Enable pull up resistor
  P1OUT |= BIT3;

  /*for (;;)
  {
    volatile unsigned int i;

    P1OUT ^= 0x01;                          // Toggle P1.0 using exclusive-OR

    i = 2000;                              // Delay
    do (i--);
    while (i != 0);
  }
}*/
while(1)
   {
       if(!(P1IN&BIT3)) //button 1.3 blinks LED
       {
       P1OUT |= BIT0;
       }
       else
       {
        P1OUT &= ~(BIT0);
       }
   }
}
