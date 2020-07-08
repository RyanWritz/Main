//CS163 HW#3
//The hash table classes function's, used to create the index
//to store user input, insert it into the hash table, delete apps
//and display them, per the user's request.

//Header file
#include "HW3.h"

//Hashing function which takes the appname and makes an index out of it
int table :: HashFunction(char * key_value, int size)
{	int TotalIndexed = 0;
    	unsigned int i = 0;

   	 for(i; i < strlen(key_value); ++i)
            	TotalIndexed += key_value[i];

    	cout << TotalIndexed % size;
    		return TotalIndexed % size;

}

//COnstructor of table class that intializes the hash table to empty
table :: table(int size)
{	 hash_table = new node *[size];

   	 hash_table_size = size;
    	 int j = 0;

    	 while( j < size)
    	 {   hash_table[j] = NULL;
         ++j;
    	 }

}	

//Destructor of the table class, which deletes any existing data in the hash table             
table ::  ~table()
{	int j = 0;
	int size = 601;

	while( j < size)
	{	if(hash_table[j] != NULL)
		{	node * temp = hash_table[j] -> next;
 			
			delete [] hash_table[j] -> Info.AppName;
			/*for(int i = 0; i < 5; ++i)
			{	if(hash_table[j] -> Info.Keyword[i] != NULL)
					delete hash_table[j] -> Info.Keyword[i];
			}*/
			delete [] hash_table[j] -> Info.Description;	
			delete hash_table[j];

			hash_table[j] = temp;
			++j;
		}  
		else 	
			++j;
	}
	
}

//Insert function to copy over data from the user into the actual hash table within a node
int table :: insert(char * key_value, char * Describe, int Rating, int size, char KWTemp[][KW], int KWNum)
{	int Index = HashFunction(key_value, size);
	
	//Checks if the hash table has no data in it, confirms and adds at index directly
	if(hash_table[Index] == NULL)	
	{	hash_table[Index] =  new node;	

		hash_table[Index] -> Info.AppName = new char[strlen(key_value) + 1];
		strcpy(hash_table[Index] -> Info.AppName,key_value);
	
		hash_table[Index] -> Info.Description = new char[strlen(Describe) + 1];
		strcpy(hash_table[Index] -> Info.Description, Describe);
		
		for(int i = 0; i < KWNum; ++i)
		{hash_table[Index] -> Info.Keyword[i]  = new char[strlen(KWTemp[i] + 1)];
		 strcpy(hash_table[Index] -> Info.Keyword[i],KWTemp[i]);
		}

		hash_table[Index] -> Info.Rate = Rating;

		hash_table[Index] -> next = NULL;
	}
	else //hash table has data, so temp pointer traverses till end of link and adds on at end
	{	node * temp = hash_table[Index];
		while(temp -> next != NULL)
			temp = temp -> next;

		temp  =  new node;
		temp -> next = NULL;

        	temp -> Info.AppName = new char[strlen(key_value) + 1];
        	strcpy(temp -> Info.AppName,key_value);

        	temp -> Info.Description = new char[strlen(Describe) + 1];
        	strcpy(temp -> Info.Description, Describe);

		for(int i = 0; i < KWNum; ++i)
                {temp-> Info.Keyword[i]  = new char[strlen(KWTemp[i] + 1)];
                 strcpy(temp-> Info.Keyword[i],KWTemp[i]);
                }

		
       		temp -> Info.Rate = Rating;

	}
}

//Matches user input for app name or keyword if it exists, otherwise
//it returns
int table :: retrieve(char * key_value, int size/* */) 
{	int Index = HashFunction(key_value, size); 
	
	display_all(Index);
}

//Displays all of the hash tables app data that has been retrieved
int table :: display_all(int Index) 
{	cout << "App Name-\n" << hash_table[Index] -> Info.AppName << endl;
	//cout << "Keywords-\n" << 
	cout << "Description-\n" << hash_table[Index] -> Info.Description << endl;
	cout << "Rating-\n" << hash_table[Index] -> Info.Rate << endl;

}

//Removes a matched node upon being called by main, through the removal option
int table :: remove(char * key_value, int size)	
{	int Index = HashFunction(key_value, size);
	node * temp;
	
	if(hash_table[Index] != NULL)
	{	while(temp != NULL)
		{	node * temp = hash_table[Index] -> next;
			delete [] hash_table[Index] -> Info.AppName;
        		//delete hash_table[j] -> Info.Keyword[KW];//Need to tweak
        		delete [] hash_table[Index] -> Info.Description;
			hash_table[Index] = temp;
        	}
		delete hash_table[Index];
	}
	else 
		return 0;
	
}	

