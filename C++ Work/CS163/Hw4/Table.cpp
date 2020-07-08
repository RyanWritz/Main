//CS163 HW#4
//The binary search tree's classes function's, used to create new nodes
//to store user input, insert it into the tree, delete apps
//and display them, per the user's request.

//Header file
#include "HW4.h"

//COnstructor of table class that intializes the binary search tree to empty
table :: table() 
{
	root = NULL;
}


//Destructor of the table class, which deletes any existing data in the binary search tree             
table ::  ~table()
{	
	remove_all();
}

//Calls upon AppData copy and AppData insert to allow it to be accessed in main
int table :: insert(char * key_value, char * Describe, int Rating, char KWTemp[][KW], int KWNum)
{
	root -> Info.copy();	
	insert(root, root -> Info);
}


//Insert function to copy over data from the temp data into actual binary search tree node
int table :: insert(node * & root, AppData & AddApp)
{	
	if(!root)
	{
		root = new node;
		root -> Info.AppName = new char[strlen(AddApp.AppName) + 1];
		strcpy(root -> Info.AppName, AddApp.AppName);
		root -> Info.Description = new char[strlen(AddApp.Description) + 1];
        	strcpy(root -> Info.Description, AddApp.Description);

        	/*for(int i = 0; i < KWNum; ++i)
        	{
                	Keyword[i]  = new char[strlen(KWTemp[i] + 1)];
                	strcpy(Keyword[i],KWTemp[i]);
        	}
		*/
       		root -> Info.Rate = AddApp.Rate;
		
		root -> left = root -> right = NULL;
	}
	else if(root -> Info.AppName > AddApp.AppName)	
		insert(root -> left, AddApp);
	
	else if(root -> Info.AppName < AddApp.AppName)
		insert(root -> right, AddApp);
}
//
int table :: retrieve(char * key_value) 
{		
	if(!root)
		return 0;
/*	else if(strcmp(root -> Info.AppName, key_value) == 1)
		display(root);
	else if(root -> left)
                retrieve(root -> left);
        else if(root -> right)
                retrieve(root -> right);
*/	
}

//Displays a singular nodes data within the binary search tree
int table :: display(node * & root)
{	
	cout << "App Name-\n" << root -> Info.AppName << endl;
	//cout << "Keywords-\n" << 
	cout << "Description-\n" << root -> Info.Description << endl;
	cout << "Rating-\n" << root -> Info.Rate << endl;
	
}

//Displays all nodes within the binary search tree
int table :: display_all()
{	
	cout << "All of the apps are the following:\n\n";
	
	if(root)
		display(root);
	/*else if(root -> left)
		display(root -> left);
	else if(root -> right)
		display(root -> right);
	*/
}	

//Calls upon recursive reomove function
int table :: remove()
{	
	//remove(key_value, root);
} 

//Removes a matched node upon being called by main, through the removal option in the BST
int table :: remove(char * key_value, node * & root)	
{	
	if(!root)
		return 0;

	if(strcmp(root -> Info.AppName, key_value) == 1)
	{	delete [] root -> Info.AppName;
		root -> Info.AppName = NULL;
		
	/*	for(int i =0; i < KWNum; ++i)
                {
                        delete root -> Info.Keyword[][i]
                        root -> Info.Keyword[][i] = NULL;
                }

	*/
                delete [] root -> Info.Description;
                root -> Info.Description = NULL;

		delete root;
		root = NULL;	
	}
}

//Removes all nodes within the binary search tree. Will be called to simulate destructor
int table :: remove_all()
{      
	remove();//Iterate or recurse here 
}

//AppData's copy calling wrapper function
int AppData :: copy()
{	
	//copy(key_value, Describe, Rating, KWTemp[][KW], KWNum);
}

//AppData's copy function to bring data from main into a temp data memeber to be passed into the BST
int AppData :: copy(char * key_value, char * Describe, int Rating, char KWTemp[][KW], int KWNum)
{	
	AppName = new char[strlen(key_value) + 1];
        strcpy(AppName,key_value);

        Description = new char[strlen(Describe) + 1];
        strcpy(Description, Describe);

        for(int i = 0; i < KWNum; ++i)
        {
		Keyword[i]  = new char[strlen(KWTemp[i] + 1)];
     	 	strcpy(Keyword[i],KWTemp[i]);
        }

        Rate = Rating;

}

