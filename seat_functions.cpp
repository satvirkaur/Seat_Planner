#include"seat_classes.cpp"

int inputs::room_count;
int seat_allot::a;
int seat_allot::b=1;
int seat_allot::branch1;
int seat_allot::branch2=1;
int seat_allot::branch_count=max_branches;

//function gets room details 
void inputs::input_room_details()
	{
		for(i=0;i<max_room;i++)
		{
			cin>>rooms[i]>>rows[i]>>columns[i];
		} 
	}



//getting roll number details from input file
void inputs::input_rollno_details()
	{
		for(i=0;i<max_branches;i++)
		{
			cin>>branch_name[i]>>start_roll_no[i]>>end_roll_no[i];
		} 
	}



//setting initial values 
void seat_allot :: set_initial_values()
	{
		input_room_details();
		input_rollno_details();
	}

//set roll numbers
void seat_allot::set_roll_no()
	{
		{		
			branch1=start_roll_no[a];
			branch2=start_roll_no[b];
		}
	}

//to set new branch after an exisiting branch

void seat_allot::set_new_branch()
	{ 			
			if(branch1 > end_roll_no[a] )
				{	
					a++;
					if(branch2<=end_roll_no[b])
						{ 
							a++;
							branch1=start_roll_no[a]; branch_count--;
						}
					else
						{  branch1=start_roll_no[a]; branch_count--;} 
		
				}
			if(branch2 > end_roll_no[b] )
				{	
					b++;
					if(branch1<=end_roll_no[a])
						{  
							b++;
							branch2=start_roll_no[b]; branch_count--;
						}
					else
						{  branch2=start_roll_no[b]; branch_count--;} 
		
				}
			if(branch_count<0)
				{ branch1=0; branch2=0;}
		
	}

//seat allocation
void seat_allot :: fix_seat()
	{
		//int seat[6][7];
		//rows= ,columns=	;	
		set_roll_no();
		for(i=0;i<max_room;i++)
			{

				int col=columns[i];
				int row=rows[i];
				int seat[row][col];

				for(j=0;j<row;j++)
					{

						for(k=0;k<col;k++ )
						{
							set_new_branch();
							if(j%2==0)
							{
								seat[j][k]=branch1;
								//cout<<"A"<<seat[j][k]<<"\t";
								branch1++;
							}
							else
							{
								seat[j][k]=branch2;
								//cout<<seat[j][k]<<"\t";
								branch2++;
							}
						
						} //cout<<"\n";

					}//cout<<"\n\n";	

	 			     
				for(int j=0;j<row;j++)
				{
					for(int k=0;k<col;k++)
						{
							cout<<seat[j][k]<<"\t";
						} cout<<"\n";
				}cout<<"\n\n";
			}	
	}
