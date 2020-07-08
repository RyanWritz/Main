//Ryan W. Writz (c) 2015
//CS163 HW#3
//Header file for the app system including the binary search tree
//Class, it's node struct, and data struct. 

//Necessary libraries to include
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>

//Necessary format to follow
using namespace std;

//Necessary constant values
const char KW = 5; 
const char APPNAME = 30;
const char DESCRIBE = 100;

//Contains the information for a single app, including name, keywords,
//description and a rating
struct AppData
{	char * AppName;//points to Array of the application name 
	char ** Keyword; //points to array of char pointers to five dynamic arrays containing at most five keywords  
	char * Description;//points to Array of application description
	int Rate; //Rating from 1-10 on how much you enjoyed the app 
	int copy();
	int copy(char * key_value, char * Describe, int Rating, char KWTemp[][KW], int KWNum);
};
//Node for a single app containing its data as a data member
struct node
{	node * left;
	node * right;
	AppData Info; 
};

//Hash Table class, gets the information supplied by the user copied into its
//hash table, uses a hash function that manipulates the app name to create an 
//index, removes apps, displays apps and matches inputs with current apps in the hash table.
class table
{  public:    
	      table();//Constructor of table class to intialize the tree 
              ~table();//Destructor of table class
	      //Inserts user data into the actual binary search tree and the node itself
	      int insert(char * key_value, char * Describe, int Rating, char KWTemp[][KW], int KWNum);
              int retrieve(char * key_value);//Looks for matches within the binary search tree  
	      int remove();//calls upon private remove
	      int display(node * & root);
              int display_all(); //Displays matched app names or keywords.
	      int copy();
   private:
              node * root; //root of the tree
	      int remove(char * key_value, node * & root);//Deletes matched app names or keywords    
	      int remove_all();
	      int insert(node * & root, AppData & AddApp);
};

