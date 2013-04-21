#include "and.h"

void And::work(void){
        while(1){
                if(in0.read() && in1.read()){
                        out0.write(1);
                        out1.write(1);
                        out2.write(1);
                        out3.write(1);
                }
                else{
                        out0.write(0);
                        out1.write(0);
                        out2.write(0);
                        out3.write(0);
                }
                wait();
        }
}
