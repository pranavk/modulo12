SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

SYSTEMC         = /usr/local/systemc

CXX = g++
CXXFLAGS = -Wall -ansi -g -O0 -Di386

INCLUDES = -I $(SYSTEMC)/include

LD = $(CXX)
LDFLAGS = $(CXXFLAGS)

LIBS = -L $(SYSTEMC)/lib-linux64 -lsystemc -Wl,-rpath,/usr/local/systemc/lib-linux

PROGRAM = modulo12

default = $(PROGRAM)

$(PROGRAM):	$(OBJS) $(DEPS)
		$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o ./$@
                
test:		$(PROGRAM)
		./$<
                
clean:;		rm -rf $(PROGRAM) *.o core* *.d *.vcd *.dump

# Cancel implicit rule
%.o: 		%.cpp

%.o:		%.cpp %.d
		$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.d:		%.cpp
		@ echo Making dependencies for $<
		@ g++ -MM $(INCLUDES) $< | sed 's#: # $*.d : #1' > $@

# Include dependency files .d
ifneq ("$(wildcard *.d)","")
	include $(wildcard *.d)
endif
