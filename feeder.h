/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#ifndef __FEEDER_H__
#define __FEEDER_H__

#include<systemc.h>

SC_MODULE(Feeder){
	sc_in<bool> clk_in;
	sc_out<bool> trigger;
	sc_out<bool> clk_out;

	void work(void);

	SC_CTOR(Feeder){
		SC_THREAD(work);
		sensitive << clk_in;
	}

};

#endif
