//Ryan W. Writz (c) 2015
//CS163 HW#2
//This program serves as a guide to those looking to check up on details 
//relating to one of their favorite food carts. These details, are the current
//wait time, average wait time and the length of the line, in order to allow people
//the ease of visiting the food cart when iti is most convenient. This program also allows for 
//people to directly enter their order, name and arrival time. The customer data is stored within
//a struct in queue nodes, while the time datas are stored within a stack. 

#include "HW2.h"

int main()
{	
	//Local variables used for loop control, and Service object 
	char Option;
	char Mode = 'e';
	char Finish = 'n';
	Service Serve;

	while(Finish == 'n')//Does not allow user to exit unless 'y' is response
	 {	cout << "Hello welcome to the Food Cart Extraoridinare App\n"
	     	     << "Should I enter Managerial Mode(m) or Enterprise Mode(e)\n";
		 cin >> Mode;
	         cin.ignore(100, '\n');
		
		if( Mode == 'e')//Enterprise or customer mode for checking current food cart info
		 {   cout  << "What would you like to do today? Your options are posted below:\n"
	    	           << "\tCheck how long our serivce is currently taking (s)\n"
			   << "\tCheck how many customers are in line (l)\n"
	                   << "\tEnter your order (o)\n\n"
			   << " (Please enter l,s, or o)\n";
		       cin >> Option;
	               cin.ignore(100, '\n');

			if( Option == 'l')//Is going to get number of customers in line
			 {	Serve.LineSize();//Call to Queue :: Count() indirectly	
			 }			

			else if( Option == 's')//Is going to look at current time stats
			 {	Serve.CurrentTimes();//Call to Stack :: peek() indirectly
			 }

			else if( Option == 'o')//Is going to add in order info
			 {	Serve.EnterOrder();//Call to Queue :: Enqueue() indirectly
			 }
		 } 
		if( Mode == 'm')//Manager mode for checking stastistics
		 {	Serve.DisplayDay();//Call to Stack :: display() indirectly 
		 }

		cout << "Are you all finished? (please enter y or n)";
		 cin >> Finish;
	         cin.ignore(100, '\n');
	  }
	return 0;
}
