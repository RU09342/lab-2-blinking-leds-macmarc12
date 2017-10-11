#include <msp430.h>

int main(void)
{
  volatile unsigned int i;

  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P1DIR |= BIT0;                            // P1.0 set as output
  P2DIR &= ~(BIT1);                  // Set P2.1 to Input

  P2REN |= BIT1;                   //Enable pull up resistor
  P2OUT |= BIT1;

 /* while(1)                                  // continuous loop
  {
    P1OUT ^= BIT0;                          // XOR P1.0
  }
}*/

while(1)
   {
       if(!(P2IN&BIT1)) //button 2.1 blinks LED
       {
       P1OUT |= BIT0;
       }
       else
       {
        P1OUT &= ~(BIT0);
       }
   }
}
