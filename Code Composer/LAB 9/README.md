## LAB 9 - PERFORMING TIMERS AND COUNTER OPERATION FOR MSP432P401R

### EXAMPLES

[**Example 9.1**](https://github.com/leander-dsouza/MSP432P401R/blob/master/Code%20Composer/LAB%209/Example9.1.c)

* Write an Embedded C programming language to utilize timers as an interrupt to blink a RED LED at P1.0.

[**Example 9.2**](https://github.com/leander-dsouza/MSP432P401R/blob/master/Code%20Composer/LAB%209/Example9.2.c)

* Write an Embedded C programming language to generate accurate hardware delay for blinking LED by initializing the PORT inside an Interrupt handler. 

### EXERCISES

[**Exercise 9.1**](https://github.com/leander-dsouza/MSP432P401R/blob/master/Code%20Composer/LAB%209/Exercise9.1.c)

* Write an Embedded C programming language to toggle RED LED for every 1 second using timers’ concept. (Set the clock from Pre scalar, refer system_MSP432P401R.c source file with data sheet).

[**Exercise 9.2**](https://github.com/leander-dsouza/MSP432P401R/blob/master/Code%20Composer/LAB%209/Exercise9.2.c)

* Write an Embedded C Programming language to toggle RED LED for 1 second and RGB LED each 1second simultaneously. Strictly use the timer32 and IQR Handlers for invoking delay.

