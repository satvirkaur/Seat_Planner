// including the seat.h file that has classes, functions and variables.
#include "seat_classes.h"

// Accessing Details of rooms that are room number, number of rows and columns.
void details :: room_details()
{
	infile.open("seat_input.in");
	infile>>t_rooms;
	for(int i=0; i<t_rooms; i++)
	{
		infile>>room_no[i]>>rows[i]>>cols[i];
	}
}

// Accessing the roll numbers and branches.
void details :: rollno_details()
{
	infile>>t_branches;
	for(int i=0; i<t_branches; i++)
	{
		infile>>branch[i]>>start_roll[i]>>end_roll[i];
	}
}

// definition of static variables.
int seat_planner :: nxt_branch;
int seat_planner :: nxt_room;

//definition of derived class's member function that calling to base class's member functions to get all details. 
void seat_planner :: get_details()
{
	room_details();
	rollno_details();
	infile.close();
}


void seat_planner :: set_room()			// definition of derived class member function. 
{
	if(nxt_room<t_rooms)				
	{
		row = rows[nxt_room];			//setting row variable with the total number of rows of next room
		col = cols[nxt_room];			//setting column variable with the total number of column of next room
		room = room_no[nxt_room];		
		nxt_room++;
	}
}

void seat_planner :: set_branch()		// definition of set_branch member function of the seat_planner
{
	if(nxt_branch==0)					// its intial stage. Sets the start and end roll numbers of two branches.
	{
		start_roll1 = start_roll[nxt_branch];
		end_roll1 = end_roll[nxt_branch];
		nxt_branch++;
		start_roll2 = start_roll[nxt_branch];
		end_roll2 = end_roll[nxt_branch];
		nxt_branch++;

	}
	else if(nxt_branch<t_branches)		
	{										//values of next branch is compared total number of branches before  
		start = start_roll[nxt_branch];		//setting the start and end roll numbers.
		end = end_roll[nxt_branch];
		nxt_branch++;
	}
	else
	{
		start = 0;					// When branches has finished start and end roll numbers are settled with value 0
		end = 0;
	}
}

void seat_planner :: set_rollno()   
{		
	if(start_roll1>end_roll1)     
	{								// to set the start and end roll numbers of first branch
		set_branch();
		start_roll1 = start;
		end_roll1 = end;
	}

	if(start_roll2>end_roll2)
	{								//to set the start and end roll numbers of second branch.
		set_branch();
		start_roll2 = start;
		end_roll2 = end;
	}

}

void seat_planner :: seat_plan() // function definition to allocate a seat to a roll number/
{
	set_branch();		// call to set_branch() member function

	for(int rm = 0; rm<t_rooms; rm++)
	{
		set_room();			// call to set_room() member function
		
		for(x=0; x<col; x++)		// Loop for number of columns in a room	
		{
			for(y=0; y<row; y++)	// Loop for number of rows in a room
			{
				set_rollno();		// call to set_rollno() function
				if(y%2==0)
				{
					seat[x][y] = start_roll1;	// seat allocation
					start_roll1++;
				}
				else
				{
					seat[x][y] = start_roll2;
					start_roll2++;
				}
				
			}
			
		}
		output(row,col);			// call to the output() function
	}
}

void seat_planner :: output(int r, int c)      // definition of output member function 
{
	outfile.open("output.txt", ios::app);
	outfile<<"\n\n\t\t Room No: "<<room<<"\n\n";
	for(x=0; x<r; x++)
	{										//Displaying Final allocated seats
		for(y=0; y<c; y++)
		{
			outfile<<seat[y][x]<<"\t\t";
		}
		outfile<<"\n";
	}
	outfile.close();	
}


