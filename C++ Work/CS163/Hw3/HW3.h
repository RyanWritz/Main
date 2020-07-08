//Ryan W. Writz (c) 2015
//CS163 HW#3
//Header file for the app system including the hash table class
//It's node struct, and data struct. 

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
};
//Node for a single app containing its data as a data member
struct node
{	node * next;
	AppData Info; 
};

//Hash Table class, gets the information supplied by the user copied into its
//hash table, uses a hash function that manipulates the app name to create an 
//index, removes apps, displays apps and matches inputs with current apps in the hash table.
class table
{  public:    
              int HashFunction(char * key_value, int size);//Hashes the app name to create an index
	      table(int size = 601);//Constructor of table class
              ~table();//Destructor of table class
	      //Inserts user data into the actual hash table
	      int insert(char * key_value, char * Describe, int Rating, int size, char KWTemp[][KW], int KWNum);
              int retrieve(char * key_value, int size /**/);//Looks for matches within the hash table   
	      int remove(char * key_value, int size);//Deletes matched app names or keywords    
              int display_all(int Index); //Displays matched app names or keywords.
   private:
               node ** hash_table; //pointer to array of pointers to create hash table
               int hash_table_size; //Size of hash table
};

