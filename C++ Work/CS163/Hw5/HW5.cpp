//Ryan W. Writz (c) 2015
//CS163 Hw#5
//This program works to get user input and enter 
//it into a graph throught the implementation of an
//array of vertices, that have linear linked lists of 
//nodes containing pointers to other vertices to create 
//adjacency lists. Through these list, it is seen how the 
//activites for summer that the user is entering are connected.


#include "HW5.h"


int main()
{	
	char Finish = 'n';	
	char ActOpt;
	table Graph;
	int i = 0;
	char ConnectOpt;	
	char Active[ACTIVITY];
	char Connect[ACTIVITY];
	char DispOpt = 'a';

	cout << "Hello, welcome to your Summer Organizer.\n"
	     << "Our system currently supports 100 activities,\n"
 	     << "if you require more space, please contact the developer.\n";
	
	while(Finish == 'n')
	{	
		cout << "Which fo the following would you like to do:\n"
		     << "\t\tEnter an activity (e)\n"
		     << "\t\tView your current Summer Organizer (v)\n\n"
		     << "Please only input either e or v\n";
		cin >> ActOpt;
		cin.ignore(100, '\n');

		if(ActOpt == 'e')//enter vertex option
    		{	
			cout << "Please enter your actvity:\n";
			cin.get(Active, ACTIVITY);
               		cin.ignore(100, '\n');

                	char * key_value = new char [strlen(Active) + 1];
                	strcpy(key_value,Active);
	
			Graph.insert_vertex(key_value, i);
			i++;
			
			if(i != 1)	
			{	
				char * current_vertex = new char [strlen(key_value) + 1];
				strcpy(current_vertex, key_value);
				
				cout << "Should this be connected to anything?(y or n)\n";
				cin >> ConnectOpt;
				cin.ignore(100, '\n');

				if(ConnectOpt == 'y')//Edge option
				{	
					cout << "What do you want to connect this activity to?\n";
					cin.get(Connect, ACTIVITY);
		                        cin.ignore(100, '\n');

                		        char * to_attach = new char [strlen(Connect) + 1];
                        		strcpy(to_attach,Connect);

					Graph.insert_edge(current_vertex, to_attach);
				}
			}
		}

		if(ActOpt == 'v')//display option
		{	
			cout << "Do you want to display all (a) or display the adjacency list (l)?\n";
			cin >> DispOpt;
			cin.ignore(100, '\n');
	
			if(DispOpt == 'l')
			{
				cout << "Please enter your actvity:\n";
                        	cin.get(Active, ACTIVITY);
                        	cin.ignore(100, '\n');

                        	char * key_value = new char [strlen(Active) + 1];
                        	strcpy(key_value,Active);

				Graph.display_adjacent(key_value);
			}
			
			if(DispOpt == 'a')
				Graph.display_all();
		}

		cout << "Are you finished? (Enter y or n)\n";
		cin >> Finish;
		cin.ignore(100,'\n');
	}

	return 0;
}
