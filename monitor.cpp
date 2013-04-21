#include "monitor.h"
#include <iostream>
void Monitor::work(void){
	while(1){
		cout << input.read() << endl;
		wait();
	}
}
