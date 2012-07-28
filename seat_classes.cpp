#include<iostream>
using namespace std;
int max_room=3;
int max_branches=6;
class inputs //It contains all the variable and functions being used in program
	{
		protected:
		int rows[5],columns[6],rooms[3];
		
		string branch_name[6];
		int start_roll_no[6], end_roll_no[6];
		int i,j,k;
		
		public:
		static int room_count;
		void input_room_details(); //Gets details of rooms. 
		void input_rollno_details();       //It displays the final output
	};

class seat_allot : public inputs
	{
		protected:
		//int seat[][];
		static int branch1, branch2,a,b,branch_count;
		int start_roll_branch1;
		int start_roll_branch2;
	
		public:
		void set_initial_values();		
		void set_roll_no();
		void fix_seat();
		void set_new_branch();


	};
