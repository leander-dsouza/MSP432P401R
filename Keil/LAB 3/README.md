## LAB 3 - INTRODUCTION TO COMPARISON AND LOGICAL OPERATIONS USING MSP432P401R

### EXAMPLES

[**Example 3.1**](https://github.com/leander-dsouza/MSP432P401R/blob/master/Keil/LAB%203/Example3.1.s)

* To familiarize the instruction sets used for comparison operator CMP, CMN, TST, TEQ with variations in CPSR.

[**Example 3.2**](https://github.com/leander-dsouza/MSP432P401R/tree/master/Keil/LAB%203/Example%203.2)

* To familiarize the instruction sets used for logical operation AND, EOR, ORR, BIC

### EXERCISES

*Note: All the values are given in decimal value convert them to hexadecimal while performing the experiment.*

[**Exercise 3.1**](https://github.com/leander-dsouza/MSP432P401R/blob/master/Keil/LAB%203/Exercise3.1.s)

* Write an assembly language to design a system based on three sensors decision, i.e. if all are true only then the system should glow light. Assume that light is interfaced with R7 register.

[**Exercise 3.2**](https://github.com/leander-dsouza/MSP432P401R/blob/master/Keil/LAB%203/Exercise3.2.s)

* Write an assembly language to connect four sensors in two sub systems. Each system has 2 sensors divided, so create a logic for the system with given condition.
        
     *	The First system holds 2 sensors interfaced with R0 & R1 registers.
     *	Second System holds 2 sensors interfaced with R3 & R4 registers.
     *	If all the sensors are high in input then make R7 Register high which is interfaced with a motor of a conveyor belt for a manufacturing application in an industry.
