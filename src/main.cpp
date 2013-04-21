/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

#include <systemc.h>
#include "feeder.h"
#include "tflipflop.h"
#include "display.h"
#include "counter.h"
#include "monitor.h"

int sc_main(int argc, char **argv){
        sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);

        //signals
        sc_signal<bool> feeder_counter_trigger;
        sc_signal<bool> feeder_counter_clk;

        sc_signal<bool> counter_display0;
        sc_signal<bool> counter_display1;
        sc_signal<bool> counter_display2;
        sc_signal<bool> counter_display3;
        sc_signal<bool> counter_display_dummy;
        sc_signal<sc_uint<4> > display_monitor;

        //initialize the instances of each component
        Feeder feeder("feeder");
        Counter counter("Counter");
        Display display("Display");
        Monitor monitor("Monitor");

        //initialize the clock
	int period = 200;
        sc_clock clk("clock",period, 0.5, period/2, true);

        //now give the connections
        feeder.clk_in(clk);
        feeder.trigger(feeder_counter_trigger);
        feeder.clk_out(feeder_counter_clk);

        counter.clk(feeder_counter_clk);
        counter.trigger(feeder_counter_trigger);

        counter.to0(counter_display0);
        counter.to1(counter_display1);
        counter.to2(counter_display2);
        counter.to3(counter_display3);

        display.in0(counter_display0);
        display.in1(counter_display1);
        display.in2(counter_display2);
        display.in3(counter_display3);

        display.output_p(display_monitor);
        monitor.input(display_monitor);

        counter.dummy(counter_display_dummy);
        display.dummy(counter_display_dummy);

        sc_trace_file *tf;
        tf = sc_create_vcd_trace_file("modulo12");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, clk, "clock");
        sc_trace(tf, feeder_counter_trigger, "feeder_counter_trigger");
        sc_trace(tf, feeder_counter_clk, "feeder_counter_clk");
        sc_trace(tf, counter_display0, "counter_display0");
        sc_trace(tf, counter_display1, "counter_display1");
        sc_trace(tf, counter_display2, "counter_display2");
        sc_trace(tf, counter_display3, "counter_display3");

        sc_trace(tf, counter.tt0, "counter_tt0");
        sc_trace(tf, counter.tt1, "counter_tt1");
        sc_trace(tf, counter.tt2, "counter_tt2");

        sc_trace(tf, counter.tff_sr0, "tff_sr0");
        sc_trace(tf, counter.tff_sr1, "tff_sr1");

        sc_trace(tf, counter.sr_out0, "and_input0");
        sc_trace(tf, counter.sr_out1, "and_input1");

	sc_trace(tf, counter.and_out_s0, "and_output0");
        sc_trace(tf, counter.and_out_s1, "and_output1");
        sc_trace(tf, counter.and_out_s2, "and_output2");
        sc_trace(tf, counter.and_out_s3, "and_output3");

        sc_trace(tf, display_monitor, "display_monitor");

        double sim_time = 10000;
        sc_start(sim_time,SC_NS);
        sc_close_vcd_trace_file(tf);
        return 0;
}
