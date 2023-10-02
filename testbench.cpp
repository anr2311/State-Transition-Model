#include <systemc.h>
#include <design.cpp>


SC_MODULE(Testbench) { /* writing the testbench module */
    sc_signal<bool> p1;
    sc_signal<bool> p2;
    sc_signal<bool> l1;
    sc_signal<bool> l2;
    sc_signal<bool> l3;

    LightController light_controller; /* instantiating the constructor module */

    void stimulus() {
        // Initialize switches p1 and p2 to false initially
        p1.write(false);
        p2.write(false);

        // Wait for some time and read initial state
        wait(10, SC_NS);
      	cout << "Initial states" << endl;
        cout << "l1: " << l1.read() << ", l2: " << l2.read() << ", l3: " << l3.read() << endl;

        // Press p1, l1 should turn on
        p1.write(true);
        wait(10, SC_NS);      	
        cout << "Press p1, l1 should turn on" << endl;
        cout << "l1: " << l1.read() << ", l2: " << l2.read() << ", l3: " << l3.read() << endl;     
      	p1.write(false); // resetting p1 switch
      	wait(10, SC_NS);
      
      	// Press p1 again, l2 should turn on
        p1.write(true);
        wait(10, SC_NS);      	
        cout << "Press p1 again, l2 should turn on" << endl;
        cout << "l1: " << l1.read() << ", l2: " << l2.read() << ", l3: " << l3.read() << endl;     
      	p1.write(false); // resetting p1 switch
      	wait(10, SC_NS);
      
      	// Press p1 again, l2 should turn off
        p1.write(true);
        wait(10, SC_NS);      	
        cout << "Press p1 again, l2 should turn off" << endl;
        cout << "l1: " << l1.read() << ", l2: " << l2.read() << ", l3: " << l3.read() << endl;     
      	p1.write(false); // resetting p2 switch
      	wait(10, SC_NS);
      
      	// Press p2, l1 should turn on
        p2.write(true);
        wait(10, SC_NS);      	
        cout << "Press p2, l1 should turn on" << endl;
        cout << "l1: " << l1.read() << ", l2: " << l2.read() << ", l3: " << l3.read() << endl;     
      	p2.write(false); // resetting p2 switch
      	wait(10, SC_NS);
      
      	// Press p2 again, l3 should turn on
        p2.write(true);
        wait(10, SC_NS);      	
        cout << "Press p2 again, l3 should turn on" << endl;
        cout << "l1: " << l1.read() << ", l2: " << l2.read() << ", l3: " << l3.read() << endl;     
      	p2.write(false); // resetting p2 switch
      	wait(10, SC_NS);
      
      	// Press p2 again, l3 should turn off
        p2.write(true);
        wait(10, SC_NS);      	
        cout << "Press p2 again, l3 should turn off" << endl;
        cout << "l1: " << l1.read() << ", l2: " << l2.read() << ", l3: " << l3.read() << endl;     
      	p2.write(false); // resetting p2 switch
      	wait(10, SC_NS);


        sc_stop(); /* stopping simulation */
    }

    SC_CTOR(Testbench) : light_controller("light_controller") {
        light_controller.p1(p1);
        light_controller.p2(p2);
        light_controller.l1(l1);
        light_controller.l2(l2);
        light_controller.l3(l3);

        SC_THREAD(stimulus);
    }
};

int sc_main(int argc, char* argv[]) {

    Testbench tb("tb");

    sc_start(); /* starting simulation */

    return 0;
}
