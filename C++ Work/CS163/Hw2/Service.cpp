//Ryan W. Writz (c) 2015
//CS163 HW#2
//Service class functions below. The Service class works within main
//but has access to Queue and Stack to manipulate the data and post
//in main. By doing this the data is kept private from the user
//through information hiding.

#include "HW2.h"

//Construtor for Service, although empty as Queue and Stack 
//already create themselves
Service :: Service()
{
}

//Destructor for Service, although empty as Queue and Stack 
//already delete themselves
Service :: ~Service()
{
}

//Calls upon the Stack's display function 
int Service :: DisplayDay()
{	cout << "Here are the results of customer average wait time and\n"
	     << "current wait times through the day of operation.\n";
	Pile.display();
}

//Allows the user to insert order info including order, name and arrival time
//This information is then passed to the Queue :: Enqueue function
int Service :: EnterOrder()
{	//Temporary arrays and int for memory 
	char TempName[NAME];
	char TempOrder[ORDER];
	int TempArrival;

	//Placing the input into the temporary arrays
	cout << "Please enter your name:\n";
	cin.get(TempName, NAME, '\n');
	cin.ignore(NAME, '\n');

	cout << "Please enter your order:\n";
	cin.get(TempOrder, ORDER, '\n');
	cin.ignore(ORDER, '\n');

	cout << "Please enter your arrival time in military time. Ex. 1530:\n";
	
	   cin >> TempArrival;
	   cin.ignore(100, '\n');
	   		
	Loop.Enqueue(TempName, TempOrder, TempArrival);//Sends Temp Arrays to Enqueue to put in Queue
	GetFood(TempArrival);
}

//Prompts the user what time they got their food and takes the diiference of the two
//Then sends it to the Stack 
int Service :: GetFood(int TempArrival)
{	int EndTime;
	int CurrentTime;

	cout << "When did you get your food?";
	cin >> EndTime;

	CurrentTime = EndTime - TempArrival;

	//Pile.push(CurrentTime);
}
//Takes in return from Count of Queue and IfEmpty to determine line size
int Service :: LineSize()
{	int Empty = Loop.IsEmpty();
	int Count = Loop.Count();
	
	if(Empty == 1)
		cout << "The line is currently empty\n";
	else
		cout << "There is currently " << Count << " in line\n";
	
}

//Takes in return of Stack::IsEmpty to check if times to display and displays
int Service :: CurrentTimes()
{	int Peek = Pile.IsEmpty();
	
	if(Peek == 1)
		cout << "There are no times to display right now.\n";
	else
	{	cout << "The current wait time and average time are:";
		Pile.peek();
	}
} 
