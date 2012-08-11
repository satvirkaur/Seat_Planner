// including the seat.cpp which has definitiond of all member functions.
//#include "seat_functions.cpp"
#include<iostream>
#include"seat_classes.h"
using namespace std;
//definition of main function
int main()
{
	cout<<"hello";
	seat_planner seatplan;        // creating object of the seat_planner class
	seatplan.get_details();	      // call to get_deatils() member function of derived class
	seatplan.valid();
	seatplan.output();

	return 0;
}
