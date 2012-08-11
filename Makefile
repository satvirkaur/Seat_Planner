all: seat

seat: seat_main.o seat_functions.o
	g++ seat_main.o seat_functions.o -o seat

seat_main.o: seat_main.cpp seat_classes.h files.h
	g++ -c seat_main.cpp

seat_functions.o: seat_functions.cpp seat_classes.h files.h
	g++ -c seat_functions.cpp 

clean:
	rm -f *.o seat output.txt


