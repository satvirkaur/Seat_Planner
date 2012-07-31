// including the seat.cpp which has definitiond of all member functions.
#include "seat_functions.cpp"

//definition of main function
int main()
{
	seat_planner seatplan;	// Object of seat_planner class
	seatplan.get_details();	// Calling get_deatils()
	seatplan.valid();
	seatplan.output();

	return 0;
}
