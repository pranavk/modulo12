/*
 * Copyright 2013, Pranav Kant <pranav913@gmail.com>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2.
 */

== Modules ==

The project consists of various modules which upon combining are yeilding a
modulo 12 counter. 

Following modules are present in the project :
* And	    : A simple And gate that outputs one when all its inputs are true.
* TFlipFlop : A TFlipFlop implementing the functionality of basic T Flip flop.
* Display   : Module receving individual bits from various T FFs separately.
* Monitor   : Final Monitor object getting counter value from the Display and
outputting it.
* Feeder    : Module generating various signals including clock to various other
modules of the project.
* SigRep    : A basic Signal replicator that essentially replicates necessary
signals to multiple signals and then feeding them to required modules.
* Counter   : This modules combines following modules : `TFlipFlop`, `And` and
`SigRep` to properly implement the functionality of a Modulo 12 Counter.

