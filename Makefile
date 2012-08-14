OBJ = seat_main.o seat_functions.o 		                       		# target
CC = g++									# compiler variable
DEBUG = -g									# debugging flag 
CFLAGS = -Wall -c $(DEBUG)							# linking flag
LFLAGS = -Wall $(DEBUG)					  	  # flag used in compiling and creating object files	

# All targets 
all: seat run

# target to generate executable file.
seat: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o seat

# target to run executable file	
run: 
	./seat

# dependencies of seat_main.cpp
seat_main.o: seat_main.cpp seat_classes.h files.h
	$(CC) $(CFLAGS) seat_main.cpp

# dependencies of seat_functions.cpp
seat_functions.o: seat_functions.cpp seat_classes.h files.h
	$(CC) $(CFLAGS) seat_functions.cpp 

# to destroy all the object and exectuable file
clean:
	rm *.o seat 

# to create tar file 	
tar:
	tar cfv seat.tar seat_main.o seat_functions.o