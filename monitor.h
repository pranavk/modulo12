#ifndef __MONITOR_H__
#define __MONITOR_H__

#include <systemc.h>

SC_MODULE(Monitor){
	sc_in<sc_uint<4> > input;

	void work(void);
	
	SC_CTOR(Monitor){
		SC_THREAD(work);
		sensitive << input;
	}
};

#endif
