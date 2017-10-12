# Simple Blink
The objective of this section was to get an LED to blink on the 5 microprocessors.

## Getting Started
Generally speaking, to get the LED blinking, or at least lighting up, you must first clear and set the correct pin to be an output.
```c
P1DIR |= BIT0;                          
P1OUT |= BIT0;
```


