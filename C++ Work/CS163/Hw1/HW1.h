//Ryan W. Writz (c) 2015
//Hw #1 CS163
//HW1.h 
//Here is the header file for the DIY (Do it yourself) class,
//the struct Part for each associated part coming via external data
//file, the struct to estalbish both the LLL for Parts and Steps 


//Libraries needed to pass the information from parts.txt to structs
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

//Generic value for name of file to bring information in from 
const char FILENAME  = 50;
const char PARTS = 100; 

//Part struct to get data from external file respectively 
struct Part
{	int PartNum;
	char * Describe;
	int Quantity;
	int StepNumUse;//could use int instead
	int * StepPartUse; 
};


//Node struct for LLL
struct node
{	node * next;
	Part PartItem; 
};

struct Step
{    int StepNum;
     int * PartsNeeded;
     int * Quantities;
};

struct stepnode
{    stepnode * next; 
     Step StepItem;
};

//Class for displaying parts or step data per the user's instructions 
class DIY
{	public:
		DIY();//Allocates pointers, creates list and reads in file
		~DIY();//Deallocates pointers
		int Display_Parts();//Displays all parts
		int Display_Steps();//Displays all steps 
		//Displays only the step you want to look for   
		int Next_Step();
	private:
		//Head and tail pointers for both Part and Step LLL
		node * part_head;
		stepnode * step_head;
		node * part_temp;
	        stepnode * step_temp;
};
