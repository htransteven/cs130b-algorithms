
all: hanoi

hanoi: ./dnc/hanoi.cpp global_inputs.cpp
	g++ -g -o hanoi $< global_inputs.cpp

clean:
	rm -rf *.o hanoi