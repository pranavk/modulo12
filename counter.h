#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <systemc.h>
#include "tflipflop.h"
#include "and.h"
#include "sig_rep.h"
SC_MODULE(Counter){

        sc_in<bool> clk;
        sc_in<bool> trigger;

        sc_out<bool> to0;
        sc_out<bool> to1;
        sc_out<bool> to2;
        sc_out<bool> to3;
        sc_out<bool> dummy;

        TFlipFlop t0;
        TFlipFlop t1;
        TFlipFlop t2;
        TFlipFlop t3;
        And and_obj;
        SigRep sig_rep;

        sc_signal<bool> tt0;
        sc_signal<bool> tt1;
        sc_signal<bool> tt2;

        sc_signal<bool> and_s0;
        sc_signal<bool> and_s1;
        sc_signal<bool> and_out_s0;
        sc_signal<bool> and_out_s1;
        sc_signal<bool> and_out_s2;
        sc_signal<bool> and_out_s3;

        sc_signal<bool> tff_sr0;
        sc_signal<bool> tff_sr1;

        sc_signal<bool> sr_out0;
        sc_signal<bool> sr_out1;

        void work(void);

 SC_CTOR(Counter) : t0("tff0"), t1("tff1"), t2("tff2"), t3("tff3"), and_obj("And_Object"), sig_rep("SigRep"){

                t0.clk(clk);
                t0.trigger(trigger);
                t0.out(to0);
                t0.out_inverse(tt0);

                t1.clk(tt0);
                t1.trigger(trigger);
                t1.out(to1);
                t1.out_inverse(tt1);

                t2.trigger(trigger);
                t2.out(tff_sr0);
                t2.clk(tt1);
                t2.out_inverse(tt2);

                t3.trigger(trigger);
                t3.clk(tt2);
                t3.out(tff_sr1);
                t3.out_inverse(dummy);
		
                sig_rep.in0(tff_sr0);
                sig_rep.in1(tff_sr1);

                sig_rep.out01(to2);
                sig_rep.out11(to3);

                sig_rep.out02(sr_out0);
                sig_rep.out12(sr_out1);

                and_obj.in0(sr_out0);
                and_obj.in1(sr_out1);
                //output of and to resets of all TFFs.
                and_obj.out0(and_out_s0);
                and_obj.out1(and_out_s1);
                and_obj.out2(and_out_s2);
                and_obj.out3(and_out_s3);

                t0.reset(and_out_s0);
                t1.reset(and_out_s1);
                t2.reset(and_out_s2);
                t3.reset(and_out_s3);

                SC_THREAD(work);
        }


};

#endif
