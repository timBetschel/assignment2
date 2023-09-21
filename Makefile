.DEFAULT: all

all: fifo sjf rr

clean:
	rm -f fifo sjf rr objectFiles/*.o


fifo: objectFiles/fifo.o objectFiles/Loader.o objectFiles/pcb.o objectFiles/Simulator.o
	g++ -Wall -Werror -std=c++11 -g -o $@ $^


sjf: objectFiles/sjf.o objectFiles/Loader.o objectFiles/pcb.o objectFiles/Simulator.o
	g++ -Wall -Werror -std=c++11 -g -o $@ $^


rr: objectFiles/rr.o objectFiles/Loader.o objectFiles/pcb.o objectFiles/Simulator.o
	g++ -Wall -Werror -std=c++11 -g -o $@ $^


objectFiles/%.o: %.cpp
	g++ -Wall -std=c++11 -g -c -o $@ $<

# Specify dependencies for each object file
objectFiles/fifo.o: fifo.cpp Loader.h pcb.h Simulator.h types.h
objectFiles/sjf.o: sjf.cpp Loader.h pcb.h Simulator.h types.h
objectFiles/rr.o: rr.cpp Loader.h pcb.h Simulator.h types.h
objectFiles/Loader.o: Loader.cpp Loader.h pcb.h types.h
objectFiles/Simulator.o: Simulator.cpp Simulator.h Loader.h pcb.h types.h
objectFiles/pcb.o: pcb.cpp pcb.h types.h
