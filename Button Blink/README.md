# Button Blink
The objective of this section is to get an LED to blink with the press of a button.

## Getting Started
This is done by clearing and setting the pins for the LED, as well as doing the same for a button depending on the pins.
```c
P5DIR &= ~(BIT5);
```
This line of code makes it so that the button pin is an input.

We must also enable pull up resistors for the button to work properly.
```c
P5REN |= BIT5 + BIT6;                   
P5OUT |= BIT5 + BIT6;
```