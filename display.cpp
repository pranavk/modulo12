/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#include"display.h"
#include <iostream>

using namespace std;

void Display::display(void){
        sc_bv<4> output;

        while(1){
                output.set_bit(0,(sc_dt::sc_logic_value_t)in0.read());
                output.set_bit(1,(sc_dt::sc_logic_value_t)in1.read());
                output.set_bit(2,(sc_dt::sc_logic_value_t)in2.read());
                output.set_bit(3,(sc_dt::sc_logic_value_t)in3.read());

		sc_uint<4> output_v = output;
		cout << output.get_bit(0) << output.get_bit(1) << output.get_bit(2) << output.get_bit(3) << endl;
		output_p.write(output_v);

                wait();
        }
}
