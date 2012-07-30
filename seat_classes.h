#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <string.h>

using namespace std;
const int size = 30;

// base class for getting the Details.
class details
{
protected:

	// Room variables
	string room_no[size]; 
	int rows[size], cols[size], t_rooms;

	// Roll Number variables
	int t_branches, start_roll[size], end_roll[size];
	string branches[size];

	// fstream variable
	ifstream infile;
	ofstream outfile;

public:
	//The functions getting Details about rooms and roll numbers of each branch.
	void room_details();
	void rollno_details();

};

// seat_planner is derived class and inherting base class deatils.
class seat_planner : public details
{
protected:

	/* array variable is used to store the seat allocation row and column wise.
	   start and end variables are being used for storing the start and end roll number of the branch.
	   start_roll1 and start_roll2 are used for storing the start roll numbers of different two branches. 
	   Similarly, end_roll1 and end_roll2 for ending roll numbers storage.
	   x and y are variable for loops.
       col and row for storing the number of rows and number of columns of each room
	*/  
	int seat[size][size], start, end, start_roll1, start_roll2, end_roll1, end_roll2;
	int x, y, col, row, count[size],startcount_roll[size],endcount_roll[size], sum;

	//the below static variable are for fetching the index of next branch and next room
	static int nxt_branch, nxt_room; 
	//short day,month,year; 
	string room, test_name, exam_date, start_time, end_time;
	
public:

	void get_details();		// to call the base class functions having all details of rooms as well as branches and their roll numbers.
	void set_branch();		// to set new branch after old one has finished.
	void set_room();		// to set new room
	void seat_plan();		// to fix the seat allocation	
	void set_rollno();		// setting roll numbers according to branches.
	void output(int r, int c);		// to display the seat allocation
	void valid();
	string branch(int rno);
	void count_rollno();
	void startend_roll();
	void exam_details();     //getting exam details
	void exam_display();     //displaying exam details as a header of the room

};


