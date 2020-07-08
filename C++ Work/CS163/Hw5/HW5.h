//Ryan W. Writz (c) 2015
//CS163 Hw#5
//The header file of the table class and all its coresponding 
//structs of information and pointers. These functions will
//all ultimately form a graph based off of user input for 
//activities over the summer and be able to display it.

//Necessary libraries
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>

//Essential format
using namespace std;

//COnstants
const int SIZE = 100;
const char ACTIVITY = 80;

//Struct prototypes to avoid order error
struct Activity;
struct node;
struct vertex;

//Struct to a char array of the activity coming in
struct Activity
{
	char * Action;	
};

//Node that is part of the adjacency list
struct node
{
       vertex * adjacent;	 
       node * next;
};

//Vertex with an array that has a pointer to nodes and flag as to 
//whether or not it has been visited in the traversal
struct vertex
{
       Activity * action;       
       node * head; 
       char Visited;          
};

//Graph class that uses a table abstraction, through an array of vertices
//and linear linked lists of nodes containing pointers back to other vertices.
//THis class is able to insert vertices, edges, display an adjacency list, and 
//display the entire graph.
class table
{
      public:
             table(int size = SIZE);    
             int insert_vertex(char * key_value, int i); 
             int find_location(char * key_value);             
             int insert_edge(char * current_vertex, char * to_attach); 
             int display_adjacent(char * key_value);        
             ~table();      
             int display_all(); 
      private:
	      int copy_input(char * key_value, Activity & AddAct, int i);
              vertex * adjacency_list;
	      int list_size;

};
