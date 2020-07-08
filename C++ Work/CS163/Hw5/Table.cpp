//Ryan W. Writz (c) 2015 
//CS163 Hw#5 
//Takes in input from the user to collect what activities
//are being done over the summer and connect them together if 
//needed to make sure related activities are together. Traversal
//is formed in a depth first manner to output the adjacency list.


#include "HW5.h"

//Constructor of graph creates an adjacecny list to set size  
table::table(int size)
{    
     int list_size = size;

     adjacency_list = new vertex[list_size];

     for(int i = 0; i < list_size; ++i)
     { 
	adjacency_list[i].action = NULL;
        adjacency_list[i].head = NULL;
	adjacency_list[i].Visited = 'n';
     }
}

//Destructor goes through adjacency list until NULL, deleting each index and sets to NULL 
table::~table()
{//still needs to delete adjacency list is only getting data right now 	
     	for(int i = 0; i < list_size; ++i)
	{	if(adjacency_list[i].action)
		{	
			delete adjacency_list[i].action;
			adjacency_list[i].action = NULL;
			delete adjacency_list[i].head;
			adjacency_list[i].head = NULL;
 		}
		else
			i = list_size - 1;

		++i;
	}		
}

//Calls upon copy_input function in order to create the vertex 
int table::insert_vertex(char * key_value, int i)
{   	
	adjacency_list[i].action = new Activity;

	copy_input(key_value, *(adjacency_list[i].action), i );	
}

//Copies in the provided Activity and copies it into the adjacency list
int table::copy_input(char * key_value, Activity & AddAct, int i)
{
   for(i; i < list_size; ++i)//Only allows options in the set amount of activities
    {	
	//Checks to see if all activity spots are full
	if(i == list_size)
		return 0;

	//Checks to see if the current index is available to add an activity 
        if(!adjacency_list[i].action)
            {
               adjacency_list[i].action -> Action = new char[strlen(key_value) + 1];
               strcpy(adjacency_list[i].action -> Action, key_value);
		
                i = list_size - 1;//Only allows to add one activity at a time
            }
    
    }
}

//Creates an edge between specified vertices
int table::insert_edge(char * current_vertex, char * to_attach)
{   
	/*
	  if(!head)
	  {
	  	current_vertex -> head -> adjacent = //to_attach 
	  	current_vertex -> head -> next = NULL;
	  }
	  else
	  {	node * temp = new node;
		current_vertex -> temp -> adjacent = //to attach
		current_vertex -> temp -> next = NULL;
	  }	
	*/ 
}

//Display vertex's adjacency list using depth first traversal 
int table::display_adjacent(char * key_value)
{	//

}

//Displays all of the contents of activities
int table::display_all()
{
	for(int i = 0; i < list_size; ++i)
	{	
		if(adjacency_list[i].action -> Action)	
		{	cout << "Activity " << i + 1 <<":"
		     	     << adjacency_list[i].action -> Action << endl;
		}	
	}
}

//Finds an index in the graph
int table::find_location(char * key_value)
{   
    /*for(int i = 0; i < list_size; ++i)
    {   
        if(adjacency_list[i].entry -> compare(key_value) != 0)
            return i;
    }
    return -1;
        //return the location of this particular key value 
	*/
}

