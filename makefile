
all: hanoi binary_search

hanoi: ./dnc/hanoi.cpp global_inputs.cpp
	g++ -g -o hanoi $< global_inputs.cpp

binary_search: ./dnc/binary_search.cpp ./dnc/merge_sort.cpp global_inputs.cpp 
	g++ -g -o binary_search $< ./dnc/merge_sort.cpp global_inputs.cpp 


clean:
	rm -rf *.o hanoi binary_search