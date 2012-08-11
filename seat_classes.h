//#include <iostream>
#include <fstream>
<<<<<<< HEAD
//#include <cstdlib>
//#include <string.h>
=======
#include <cstdlib>
#include <stdio.h>
#include "files.h"
#include <string.h>
>>>>>>> dd27b8864cfe93644892b02a5d48a0f1682eb035

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
	// Getting Details about room and branch.
	void room_details();
	void rollno_details();

};

// Derived class from base class (details)
class seat_planner : public details
{
protected:

	int seat[size][size][size];	// For storing seat plan
	int start, end, start_roll1, start_roll2, end_roll1, end_roll2;
	int x, y, col, row, count[size], choice, sum;

	// For next branch and next room
	static int nxt_branch, nxt_room; 
	
	// For test deatils 
	string room, exam_date, start_time, end_time, test_name; 
	//char test_name[size];
	
public:

	void get_details();	// Getting deatils
	void set_branch();	// To set new branch after old one has finished.
	void set_room();	// To set new room
	void seat_plan();	// to fix the seat allocation	
	void set_rollno();	// Setting roll numbers according to branches.
	void output();	// To display the seat allocation
	void valid();	// Validations for strategy
	string branch(int rno);	// Return branch name
	void count_rollno();	// Total Students in room
	void exam_details();	// Getting exam details
	void exam_display();	// Displaying exam details at the of room
	void report_choice();
	// To set remaining seats on empty places
	void fill_space(int start_roll, int end_roll); 

};


