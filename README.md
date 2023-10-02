# State-Transition-Model
This repo contains a SystemC code (C++ code + SystemC library) to control a set of 3 lights based on the switches pressed

The switches p1 and p2 act as the inputs and the lights l1, l2 and l3 are switched based on the below transition table:

![image](https://github.com/anr2311/State-Transition-Model/assets/72514473/4e71af60-5c09-464b-95af-b1b7f4bf7156)

Where, NL (No lights on), L1 (Light L1 is turned on),	L2 (Light L2 is turned on) and	L3 (Light L3 is turned on)

![image](https://github.com/anr2311/State-Transition-Model/assets/72514473/b40ac535-e068-4869-93f9-6f74657f133f)

The design.cpp contains the logic in which based on the inputs p1 and p2, the states of the system are controlled and the testbench.cpp contains the order in which the inputs p1 and p2 are serially excited.
