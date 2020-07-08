//Ryan W. Writz (c) 2015
//CS163 HW#3
//For this homework, we are to provide an app system 
//that is capable of entering apps, with a name field,
//description field, rating filed and a keyword field.
//This system should also be able to display an app 
//on request, as well as delete it. The implementation of
//this system is to be through the use of a hash table
//that uses chaining as a collision resolution technique.

//Header File
#include "HW3.h"

//Main interface of app system
int main()
{	//Loop control variables
	char Finish = 'n';
	char Option = 'm';
	char App[APPNAME];//Temp array to get app name
	table Collection;//Object of the table class
	int KWNum;//Number of keywords to take 
	int Rating;//Temp int for rating
	int size = 601;//Size of the hash table's array of pointers

	//Welcoming message to inform user of the app system capabilities
	cout << "Hello, welcome to the Mystical App Machine, where you\n"
	     << "can do the following:\n"
	     << "\tInsert an application\n"
	     << "\tDelete an application\n"
	     <<"\t\tAND\n"
	     << "\tFind all matches for an app based on a keyword search and display them\n";

	while(Finish == 'n') //Loop control to keep user from escaping without being done     
	{	cout << "What would you like to do today? (Choose i for inserting, m for match or d for delete)\n";
	 	cin >> Option;
		cin.ignore(100,'\n');

		//Insert option
		if(Option == 'i')
		{	cout << "What is the name of your app to add?\n";
			cin.get(App, APPNAME);
			cin.ignore(100, '\n');

			char * key_value = new char [strlen(App) + 1];
			strcpy(key_value,App);

        		cout << "What is a description of the app?\n";
			char * Describe = new char [DESCRIBE];
      			cin.get(Describe,DESCRIBE);
 		        cin.ignore(100, '\n');

			cout << "How many keywords do you want? (maximum of 5)\n";
			cin >> KWNum;
			cin.ignore(100, '\n');
			
			char KWTemp[KWNum][KW];
			
			for(int i = 0; i < KWNum; ++i)
			{	cout << "Please enter your keyword?";
				cin.get(KWTemp[i], KW);
				cin.ignore(100, '\n');
			}

 			cout << "What would you like to rate this app? (1-5)\n";
			cin >> Rating;
			cin.ignore(100,'\n');
			
			//Sends in gathered info to be copied over to actual hashtable
			Collection.insert(key_value, Describe,Rating,size, KWTemp, KWNum);
		}
		//Matching option, to retrieve and display
		if(Option == 'm')
		{	cout << "What app would you like to find?\n";
			cin.get(App, APPNAME);
			cin.ignore(100, '\n');

			char * key_value = new char [strlen(App) + 1];
                        strcpy(key_value,App);
			
			//Sends in gathered info to compare with current contents of hash table and display
			Collection.retrieve(key_value, size);
		}
		//Delete option
		if(Option == 'd')
		{	cout << "What app would you like to delete?\n";
			cin.get(App, APPNAME);
                        cin.ignore(100, '\n');

                        char * key_value = new char [strlen(App) + 1];
                        strcpy(key_value,App);
			
			//Sends in app name to delete and deletes it
			Collection.remove(key_value, size);
		}
		
		cout << "Are you all finished with your apps for now?\n";
		cin >> Finish;
		cin.ignore(100,'\n');
	}      

	return 0;
}
