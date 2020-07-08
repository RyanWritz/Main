//Ryan W. Writz (c) 2015 
//CS163 HW#2 
//Header file including the prototypes of the Service class, Queue class
//and Stack class, as well as all of its members and member functions 
//that make up the operations of each ADT


//Necessary libraries to include 
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>

//Necessary format to follow
using namespace std;

//Constants to be used when dynamically allocating arrays
const int TIMES = 5;
const char NAME = 30;
const char ORDER = 50;
const int MAX = 5;

//Customer struct which points to the information someone inputs 
//upon making an order
struct Customer
{	char * Name;
	char * Order;
	int  ArrivalTime;
};

//Queue node that contains a next pointer and an object
//of Customer for each node
struct node
{	node * next;
	Customer Person;
};

//Timestat node for the Stack class that has a next pointer
//and also points to two int arrays containing the Current
//Wait times as well as the Average Wait times
struct TimeStat
{	TimeStat * next;
	int * CurrentWait;
	int * AverageWait;
};

//Queue class that contains nodes with Customer Structs inside of them pointing to the 
//Order information. Upon someone entering an order the Queue adds the order. It can
//also delete the next person in line's node when the order is fufilled, as well as 
//display the entirety of all the customer data in the Queue, and check if it is full
//or empty
class Queue
{ public:
	Queue();
	~Queue();
	int peek();
	int Dequeue(); 
	int Enqueue(char * TempName,char * TempOrder, int  TempArrival);
	int IsEmpty();
	int Count();
 private:
	node * rear;
};

//Stack class that contains TimeStat nodes pointing to both Average and Current Wait times,
//Calcultes Current and Average Times upon a person getting their food (after the Queue
//performs a dequeue). Can add this infromation,remove from the top, peek at the top,
//display all of the current and average times, and check if full or empty.
class Stack
{ public:
	Stack();//Constructor which creates the stack with a TimeStat node and two dhynamically allocate arrays
	~Stack();//Destructor which destroys the stack TimeStat nodes as well as the dynamically allocated arrays
	int peek();//Displays the value at top_index
	int push();//Pushes on a new top_index value and increments top_index
	int pop (); //Pops off the top_index value and decrements top_index
	int display();//Displays the values of the stack
	int IsEmpty();
  private:
	TimeStat * head;//pointer to first Timestat node 
	int top_index;//Current top of stack 
};

//Service Class calls upon the Stack and Queue in order to pass information between the 
//two, as well as execute their functions
class Service
{ public:
	Service();//Constructor of Service Class
	~Service(); //Destructor of Service class
 
	int LineSize();//Outputs the size of line (or customers in stack) to user 
	int CurrentTimes(); //Outputs the top current wait time and  average time from top of stack (peek)
	int DisplayDay();//Displays stack  statistics and the total number of people served
	

	int EnterOrder();//Allows user to input their order, name, and start time which  enters their info in the queue
	int GetFood(int TempArrival); //Allows user to input time they get food, this creates their time statistic in the stack
private: 
	Queue Loop;
	Stack Pile;
};

