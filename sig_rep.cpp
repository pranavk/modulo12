/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#include "sig_rep.h"

void SigRep::work(void){

        while(1){
                out01.write(in0.read());
                out02.write(in0.read());
                out11.write(in1.read());
                out12.write(in1.read());
                wait();
        }
}
