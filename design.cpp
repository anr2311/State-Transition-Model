#include <systemc.h>

SC_MODULE(LightController) { /*The main logic module that controls the lights */
    sc_in<bool> p1; // input switch p1
    sc_in<bool> p2; // input switch p2

    sc_out<bool> l1; // output light l1
    sc_out<bool> l2; // output light l2
    sc_out<bool> l3; // output light l3

    enum State { /*using an enum to transition between states */
        OFF,
        ON_L1,
        ON_L2,
        ON_L3
    };

    State state;

    void transition() {
        while (true) {
            wait();

            if (p1.read() == true) {
                // Logic when switch p1 is pressed
                switch (state) {
                    case OFF: // case where all lights where off and p1 is pressed, l1 should be turned on
                        state = ON_L1;
                  		l1.write(true);
                  		l2.write(false);
                  		l3.write(false);
                        break;
                    case ON_L1: // case where l1 is on and p1 is pressed, l2 should be turned on
                        state = ON_L2;
                  		l1.write(false);
                  		l2.write(true);
                  		l3.write(false);
                        break;
                    case ON_L2: // case where l2 is on and p1 is pressed, all lights turned off
                        state = OFF;
                  		l1.write(false);
                  		l2.write(false);
                  		l3.write(false);
                        break;
                    case ON_L3: // case where l3 is on and p1 is pressed, all lights turned off
                        state = OFF;
                  		l1.write(false);
                  		l2.write(false);
                  		l3.write(false);
                        break;
                    default:
                        break;
                }
            } else if (p2.read() == true) {
                	// Logic when switch p2 is pressed
                switch (state) {
                    case OFF: // case where all lights where off and p2 is pressed, l1 should be turned on
                        state = ON_L1;
                  		l1.write(true);
                  		l2.write(false);
                  		l3.write(false);
                        break;
                    case ON_L1: // case where l1 is on and p2 is pressed, l3 should be turned on
                        state = ON_L3;
                  		l1.write(false);
                  		l2.write(false);
                  		l3.write(true);
                        break;
                    case ON_L2: // case where l2 is on and p2 is pressed, all lights turned off
                        state = OFF;
                  		l1.write(false);
                  		l2.write(false);
                  		l3.write(false);
                        break;
                    case ON_L3: // case where l3 is on and p2 is pressed, all lights turned off
                        state = OFF;
                  		l1.write(false);
                  		l2.write(false);
                  		l3.write(false);
                        break;
                    default:                        
                        break;
                }
            }
        }
    }

  SC_CTOR(LightController) : state(OFF) { /* constructor definition for the logic module */
        SC_THREAD(transition);
        sensitive << p1 << p2; /* The module is sensitive to input switches p1 and p2 */
    }
};
