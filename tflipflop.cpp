#include "tflipflop.h"
#include <iostream>

void TFlipFlop::work(void){
        bool prev = 0;

        bool trigger_v;
        bool output_v;
        bool output_inverse_v;
        wait();

	while(1){
                if(reset.read()){
                        prev = 0;
			out.write(0);
                        wait();
                }

                trigger_v = trigger.read();
                if(trigger_v){
                        bool prev_t = prev==1 ? 0 : 1;
                        out.write(prev_t);
                        out_inverse.write(prev);
                        prev = prev_t;
                }else{
                        bool prev_t = prev==1 ? 0 : 1;
                        out.write(prev);
                        out_inverse.write(prev_t);
                }

                wait();
        }
}
