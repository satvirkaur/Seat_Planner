//#include <iostream>
#include <iostream>
//#include <stdio.h>
#include "files.h"
#include"seat_classes.h"
#include <string.h>


// Reading room deatils from I/P file
void details :: room_details()
{
	infile.open(input_file);
	infile>>t_rooms;
	for(int i=0; i<t_rooms; i++)
	{
		infile>>room_no[i]>>rows[i]>>cols[i];
	}
}

// Reading branch deatils from I/P file
void details :: rollno_details()
{
	infile>>t_branches;
	for(int i=0; i<t_branches; i++)
	{
		infile>>branches[i]>>start_roll[i]>>end_roll[i];
	}
}

// Definition of static variables.
int seat_planner :: nxt_branch;
int seat_planner :: nxt_room;

// Exam Details
void seat_planner::exam_details()
{
	cout<<"\n1. Enter the Name of the Test: ";
	cin>>test_name;	//getline(cin, test_name);
	cout<<"\n2. Enter Date of the Test (eg 13-03-1990): ";
	cin>>exam_date;
	cout<<"\n3. Timing (eg 12:00a.m  2:00p.m): "; 
	cin>>start_time>>end_time;
}

// To display exam deatils
void seat_planner::exam_display()
{
	outfile.open("output.txt", ios::app);
	outfile<<"\n\n\t\t\t"<<test_name<<"  Test\n\n\tDate:		"
		<<exam_date<<"\n\tTimings:	"<<start_time<<"  To  "<<end_time;
}

void seat_planner :: get_details()
{
	room_details();
	rollno_details();
	infile.close();
}

void seat_planner :: set_room()	// Setting room deatils 
{
	if(nxt_room<t_rooms)				
	{
		row = rows[nxt_room];	// Rows of room
		col = cols[nxt_room];	// Columns of room
		room = room_no[nxt_room];	// Room name		
		nxt_room++;	// Next room
	}
}

void seat_planner :: set_branch()	// set_branch of seat_planner
{
	if(nxt_branch==0)	// Sets start and end roll nos of two branches.
	{
		start_roll1 = start_roll[nxt_branch];
		end_roll1 = end_roll[nxt_branch];
		nxt_branch++;
		start_roll2 = start_roll[nxt_branch];
		end_roll2 = end_roll[nxt_branch];
		nxt_branch++;

	}
	else if(nxt_branch<t_branches)		
	{										
		start = start_roll[nxt_branch];	// Start roll no
		end = end_roll[nxt_branch];	// End roll no
		nxt_branch++;	// Increment branch
	}
	else
	{	// When branches are finished
		start = 0;
		end = 0;
	}
}

void seat_planner :: set_rollno()   
{		
	if(start_roll1>end_roll1)     
	{	// To set start and end roll no. of first branch
		set_branch();
		start_roll1 = start;
		end_roll1 = end;
	}

	if(start_roll2>end_roll2)
	{	// To set start and end roll no. of second branch.
		set_branch();
		start_roll2 = start;
		end_roll2 = end;
	}

}

void seat_planner :: seat_plan()	// Allocate seats
{
	set_branch();	// Calling set_branch() 
	
	for(int rm = 0; rm<t_rooms; rm++)
	{
		set_room();	// Call to set_room() member function
		
		for(x=0; x<col; x++)		// For number of columns in a room	
		{
			for(y=0; y<row; y++)	// For number of rows in a room
			{
				set_rollno();       // Call to set_rollno() function
				if(y%2==0)
				{
					seat[rm][x][y] = start_roll1;	// seat allocation
					start_roll1++;
				}
				else
				{
					seat[rm][x][y] = start_roll2;
					start_roll2++;
				}
			}
			
		}
	}
	if(start_roll1 < end_roll1)        
	{
		fill_space(start_roll1,  end_roll1);
	}
	if(start_roll2 < end_roll2)
	{
		fill_space(start_roll2,  end_roll2);	
	}	
}

void seat_planner :: output()	// To display seat plan
{
	
	for(int a=0;a<t_rooms;a++)
	{
	
	sum=0;
	count_rollno();
	exam_display();
	outfile<<"\n\n\t\t Room No: "<<room_no[a]<<"\n\n";
	for(x=0; x<rows[a]; x++)
	{										
			for(y=0; y<cols[a]; y++)
			{
				outfile<<branch(seat[a][y][x])<<"-"<<seat[a][y][x]
				<<"\t";
			}
			outfile<<"\n";
	}
	outfile<<"\n";
	for(int i=0; i<t_branches; i++)
	{
		if(count[i] != 0)
		{
			outfile<<branches[i]<<":\t"<<count[i]<<endl;
		}
	}
	outfile<<"Total:\t"<<sum;
	outfile.close();
	}	
}

void seat_planner :: valid()
{
	int students=0, seats=0;
	char choice;

	for(x=0; x<t_branches; x++)
	{
		students += (end_roll[x]-start_roll[x])+1;
	}
	for(x=0; x<t_rooms; x++)
	{
		seats += (rows[x] * cols[x]);
	}

	if(students > seats)
	{
		system("clear");
		cout<<"\nThis strategy is not applicable because of less seats."
			<<endl<<"Total Seats: "<<seats<<endl
			<<"Total students: "<<students<<endl
			<<"More Seats Required: "<<(students-seats)<<endl
			<<"Please add more rooms in input file."<<endl;
	}
	else if(seats > students || seats == students)
	{
		system("clear");
		cout<<"\nStrategy applicable. Press 'Y' to continue."<<endl;
		cin>>choice;
	
		switch(choice)
		{
			case 'Y':
				exam_details();
				//report_choice();
				seat_plan();	// Call to seat_plan() function
				cout<<"\n Check output.txt file for seat plan."<<endl;
				break;
		
			default:
				cout<<"\nWrong Choice"<<endl;
				break;
		}

	}
}

string seat_planner :: branch(int rno)
{
	string brnch;
	for(int i=0; i<t_branches; i++)
	{
		if(rno>=start_roll[i] && rno<=end_roll[i])
		{
			brnch = branches[i];
			count[i] = count[i] + 1;
			sum += 1;
			break;
		}
	}
	return brnch;
}


void seat_planner::count_rollno()
{
	for(x=0;x<t_branches;x++)
	{
		count[x]=0;
	}
}


void seat_planner :: report_choice()
{
	
	do 
	{
		system("clear");
		cout<<"\n1. Enter 1 to generate the report Room-wise"
		<<"\n2. Enter 2 to generate the Report Branch-wise\n"
		<<"3. Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
			cout<<"\n you entered 1";
			break;
		
			case 2:
			cout<<"\nyou entered 2";		
			break;
						
			default:
			cout<<"Wrong Choice!!!!! Enter your choice again";
		}
	} while(choice!=1 && choice!=2);
}

//used to fill the remaining seats.
void seat_planner :: fill_space(int start_roll, int end_roll)
{
	for(int r=0;r<t_rooms;r++)
	{
		for(x=0;x<cols[r];x++)
		{
			for(y=0;y<rows[r];y++)
			{
				if( seat[r][x][y] == 0 && start_roll <= end_roll)
				{

					seat[r][x][y]=start_roll;
					start_roll++;
				}
			}
		}		
	}
			
}

