#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1DIR |= 0x06;                            // Set P1.6 to output direction

  for (;;)
  {
    volatile unsigned int i;

    P1OUT ^= 0x01;                          // Toggle P1.0 using exclusive-OR
    P1DIR ^= 0x06;                          // Toggle P1.6 using exclusive-OR and make another for loop for P1.6

    i = 2000;                              // Delay
    do (i--);
    while (i != 0);
  }
}
