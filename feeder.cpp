/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#include "feeder.h"
#include <iostream>

void Feeder::work(void){
	bool clk_v;
	const bool trigger_v = 1;
	
	while(1){
		clk_v = clk_in.read();
		clk_out.write(clk_v);
		trigger.write(trigger_v);
		wait();
	}
}
