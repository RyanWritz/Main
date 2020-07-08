//Ryan W. Writz (c) 2015 
// Hw #1 CS163 
// HW1.cpp
// Program brings in data from external data file "parts.txt" and stores the
// Information separately into Part Number, Description, Quantity Provided,
// Number of steps that use the part, list of steps that use the part, such that
// There is some common separator such as a :. Once the data is extracted
// It will be separated through each element of each part and stored into a 
// Struct (in which each separate part will have its own struct). With the data
// Stored in separate part structs, the structs are then put as separate cells
// Within 2 Linear Linked Lists, one for the steps and one for the parts.
// Through this implementation, a user should be able to ask for which parts are
// Used on which steps. 

#include "HW1.h"

int main()
{       // The object of the DIY class
	DIY DoItYourself; 
	//Local variables being used in main
	char filename[FILENAME]; 
	char Done = 'n';
	char ParOrStep = 's';

	cout << "Hello welcome to the automated Build Your Own Project Program.\n"
	     << "Here we will help guide you step by step on how to build your project.\n";

	while(Done != 'y' && ((ParOrStep != 'p' || ParOrStep != 's' )|| ParOrStep != 'l'))  
	{       cout << "Great. We've now uploaded your file into our system and can help guide you.\n"
	             << "Would you like to look for a step(l), see all steps(s)\n" 
		     << "or see all parts(p)?(answer with l, p or s)\n";
		cin >> ParOrStep; 
			if(ParOrStep == 'p')//Procedure for displaying all parts
			{	DoItYourself.Display_Parts();
			}
			if(ParOrStep == 'l')//Procedure for displaying specified step
			{	//DoItYourself.Next_Step();
			}
			if(ParOrStep == 's')//Procedure for displaying all steps
			{	cout << "Your Step information is as follows:\n";
				DoItYourself.Display_Steps(); 
 			} 
		cout << "Are you all finished? (answer with n or y)\n";
		cin >> Done;
	}
	return 0;
}	
