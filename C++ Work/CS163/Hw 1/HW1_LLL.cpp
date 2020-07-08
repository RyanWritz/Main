//Ryan W. Writz (c) 2015 
//Hw #1 CS163
//HW1_LLL.cpp
//Here the functions for the DIY (Do it yourself) class are implemented
//In order to set up the information from the external data file appropriately 


#include "HW1.h" 

//Constructor that will set up head and tail pointers appropriately
//fix on a new node. This should make sure no matter you have at least
//a list of one node for both LLLs.
DIY :: DIY()
{	part_temp = part_head = new node;//setting up part LLL
	step_temp = step_head = new stepnode;//setting up step LLL
	part_head -> next = NULL;
	part_temp -> next = NULL;
	step_head -> next = NULL;
	step_temp -> next = NULL;
	part_head -> PartItem.Describe = new char[100];//Adjust so that you use temp arrays
	step_temp -> StepItem.PartsNeeded = new int[100];
	step_temp -> StepItem.Quantities = new int[100];
	ifstream ReadIn;	
	
	ReadIn.open("parts.txt");

	if(ReadIn.good())//Check to see if the connection to file is good
	{	while(!ReadIn.eof()) //Reading in till end of the file
		{	//Reading in of all file data into node PartItem's members  
			ReadIn >> part_temp -> PartItem.PartNum;
			ReadIn.ignore(100, ':');
			ReadIn.getline( part_temp -> PartItem.Describe, 100, ':');
			ReadIn >> part_temp -> PartItem.Quantity;
			ReadIn.ignore(100, ':');
			ReadIn >> part_temp -> PartItem.StepNumUse;
			ReadIn.ignore(100, ':');
			part_temp -> PartItem.StepPartUse = new int[part_temp -> PartItem.StepNumUse];  
			for( int i=0; i < part_temp -> PartItem.StepNumUse; ++i)
				{ReadIn >> part_temp -> PartItem.StepPartUse[i];
				ReadIn.ignore(100,':');
				} ReadIn.ignore(100,'\n'); 
			

			//sorted LLL insert 
			part_temp -> next = new node;
			part_temp = part_temp -> next;
			part_temp -> PartItem.Describe = new char[100];//Adjust so that you use temp arrays
			part_temp -> next = NULL;//still needs to sort 
			
		}
	}	
	ReadIn.close();
	ReadIn.clear();
		
		//Handling conditions for creation fo extra nodes 
		part_temp = part_head;
		while(part_temp -> next -> next != NULL)
			part_temp = part_temp -> next;
			if(part_temp -> next -> next == NULL)
				{delete part_temp -> next;
				 part_temp -> next = NULL;
				 part_temp = NULL;
				 part_temp = part_head;
	  			}
		//Assigning local varaibles and realligning part_temp to traverse
	/*	part_temp = part_head;
			int j= 0;
			int k= 0;

		//Checks for if Step Number in PartItem and StepItem match, when matches found, 
                //Puts data from Part struct node into Step Struct stepnode, while finding the data
                //should also create the Part LLL  
		while(part_temp -> next != NULL)
		{ 	while( part_temp -> PartItem.StepPartUse[j] != step_temp -> StepItem.StepNum
			       || part_temp -> PartItem.StepPartUse[j] != '\n')
			{ 	if( part_temp -> PartItem.StepPartUse[j] == step_temp -> StepItem.StepNum)
		seg fault here          {	step_temp -> StepItem.PartsNeeded[k] = part_temp -> PartItem.StepPartUse[j];
						step_temp -> StepItem.Quantities[k] = part_temp -> PartItem.Quantity;
					}
			 	if(part_temp -> PartItem.StepPartUse[j] == '\n')
					part_temp = part_temp -> next;
				else ++j;

			}
			++k;
			step_temp -> next = new stepnode;
			step_temp = step_temp -> next;
			step_temp -> StepItem.PartsNeeded = new int[100];
			step_temp -> StepItem.Quantities = new int[100];
		}
		
	  */
}

//Destructor that will dereference all the pointers used 
DIY :: ~DIY()
{	delete [] part_head;
	delete [] part_temp;
	delete [] step_head;
	delete [] step_temp;
}

//Displays the part you want to look at as well as its 
//description, quantity, the steps that use it and 
//the number of steps that use it 
int DIY :: Display_Parts()
{	if(!part_head)
		return 0;	
	int i=0;
	node * part_current = part_head;
	cout << "Here is your Part List.\n";

	while(part_current != NULL)//Probably causing problems
		{ //if(part_current -> PartItem.PartNum != 0)
		    {	cout << "Part #"<< part_current -> PartItem.PartNum << ":\n";
			cout << "Description:\n" << part_current -> PartItem.Describe << endl;
			cout << "\t" << "Quanity- " << part_current -> PartItem.Quantity << endl; 
			cout << "\t" << "Number of steps that use this part- "; 
                        cout << part_current -> PartItem.StepNumUse << endl;  
			cout <<"\t" << "Steps that use this part-";
	
			for(int i=0; i < part_current -> PartItem.StepNumUse; ++i)
				cout << part_current -> PartItem.StepPartUse[i] <<",";
			cout << endl;
		    }	
			part_current = part_current -> next;
		 
		}
	
}
//Displays the step you want to look at as well as the
//Parts required and their quantity 
int DIY :: Display_Steps()
{	/*step_temp = step_head;
	
	if(!step_head)
		return 0;	
	
	int a = 0;
	int b = 0;
			cout << "Step #" << step_temp -> StepItem.StepNum << ":\n";
	while(step_temp != NULL)
		{	while(step_temp -> StepItem.PartsNeeded[a] != '\n')
				{cout << "\t" <<"Part #" << step_temp -> StepItem.PartsNeeded[a];
				while( step_temp -> StepItem.Quantities[b] != '\n')
					cout << "\t\t\t" << "Quanity- " << step_temp -> StepItem.Quantities[b] << endl;
				}
				step_temp = step_temp -> next;
		}	*/
}

//Will move to next step/part # when user is prompted 
int DIY :: Next_Step()  
{	/*char NStep = 'y';
	int StepToGo;

	if(StepToGo < 0 || StepToGo == 0)
 	{	cout << "What step number would you like to go to?";
		cin >> StepToGo;	
	}cout << "Here is the information for Part #" << StepToGo<< ":\n";
//Display one step here
	if(NStep != 'n')
	{	cout << "Would you like to go to the next step?\n";
		cin >> NStep;
		if( NStep != 'y' && step_temp -> next != NULL) 
		     step_temp = step -> next; 
		else return 0;
	}
	return 0;*/
}

