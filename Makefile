CC=g++

#SOURCES=seat.h seat.cpp seat_main.cpp
#OBJECTS=$(SOURCES):.cpp=.o
#EXECUTABLE=seat

all: 
	$(CC) -o seat seat_main.cpp

#seatdbg: 

#	$(CC) -og seat seat_main.cpp

clean:
	rm -f *.o seat output.txt

