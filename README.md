# State-Transition-Model
This repo contains a SystemC code (C++ code + SystemC library) to control a set of 3 lights based on the switches pressed

The switches p1 and p2 act as the inputs and the lights l1, l2 and l3 are switched based on the below transition table:

State	Input	Next State
NL	P1	L1
NL	P2	L1
L1	P1	L2
L1	P2	L3
L2	P1	NL
L2	P2	NL
L3	P1	NL
L3	P2	NL

Where, NL (No lights on), L1 (Light L1 is turned on),	L2 (Light L2 is turned on) and	L3 (Light L3 is turned on)

![image](https://github.com/anr2311/State-Transition-Model/assets/72514473/8c98a5b7-d46c-4733-87b1-e849764de58b)

The design.cpp contains the logic in which based on the inputs p1 and p2, the states of the system are controlled and the testbench.cpp contains the order in which the inputs p1 and p2 are serially excited.
