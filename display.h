/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <systemc.h>

SC_MODULE(Display){
        sc_in<bool> dummy;

        sc_in<bool> in0;
        sc_in<bool> in1;
        sc_in<bool> in2;
        sc_in<bool> in3;

	sc_out<sc_uint<4> > output_p;
	
        void display(void);

        SC_CTOR(Display){
                SC_THREAD(display);
                sensitive << in0 << in1 << in2 << in3;
        }
};

#endif
