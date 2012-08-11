// including the seat.cpp which has definitiond of all member functions.
//#include "seat_functions.cpp"
#include<iostream>
#include"seat_classes.h"
using namespace std;
//definition of main function
int main()
{
<<<<<<< HEAD
	cout<<"hello";
	seat_planner seatplan;        // creating object of the seat_planner class
	seatplan.get_details();	      // call to get_deatils() member function of derived class
=======
	seat_planner seatplan;	// Object of seat_planner class
	seatplan.get_details();	// Calling get_deatils()
>>>>>>> dd27b8864cfe93644892b02a5d48a0f1682eb035
	seatplan.valid();
	seatplan.output();

	return 0;
}
