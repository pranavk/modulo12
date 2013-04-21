/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#ifndef __TFLIPFLOP_H__
#define __TFLIPFLOP_H__

#include<systemc.h>

SC_MODULE(TFlipFlop){

        sc_in<bool> clk;
        sc_in<bool> trigger;
        sc_in<bool> reset;

        sc_out<bool> out;
        sc_out<bool> out_inverse;

        void work(void);

        SC_CTOR(TFlipFlop){
                SC_THREAD(work);
                sensitive << clk.pos();
                sensitive << reset.pos();
        }
};

#endif
