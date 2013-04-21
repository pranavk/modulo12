/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#include "monitor.h"
#include <iostream>
void Monitor::work(void){
	while(1){
		cout << input.read() << endl;
		wait();
	}
}
