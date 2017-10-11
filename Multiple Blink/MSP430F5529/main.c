#include <msp430.h>

int main(void)
{
  volatile unsigned int i;

  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P1DIR |= BIT0;                            // P1.0 set as output
  P4DIR |= BIT7;


  while(1)
      {
          if(x>=8000)
          {
              P1OUT ^= BIT0;                          // XOR P1.0
              x= 0;
          }
          if(y>=16000)
          {
              P4OUT ^= BIT7;
              y=0;
          }
         x++;
         y++;
      }
}

