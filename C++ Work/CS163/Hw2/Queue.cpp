//Ryan W. Writz (c) 2015
//CS163 HW#2
//This Queue class serves as the data structure holding customer information 
//for each order that is made at the food carts, it adds on new customers at 
//the back and removes the front first (FIFO) 

#include "HW2.h"

//Constructor of Queue initializes rear pointer to NULL
Queue :: Queue()
{	rear = NULL;	
}

//Destructor deletes rear and its data if it is not NULL
Queue :: ~Queue()
{if(rear)
	{while(rear -> next) 
		{delete [] rear -> Person.Name;
		delete [] rear -> Person.Order;
		delete rear;
		rear -> next;
	}	}
 else 
	return;
}

//Creates a new node to be added on at rear of Queue that includes the customer information 
int Queue :: Enqueue (char * TempName,char * TempOrder, int  TempArrival) 
{	int count = 0;	

	if(!rear)
	{	rear = new node;
		rear -> next = rear;
	}
		rear -> Person.Name = new char[strlen(TempName)+1];
		strcpy(rear -> Person.Name, TempName);
		rear -> Person.Order = new char[strlen(TempOrder)+1];
		strcpy(rear -> Person.Order, TempOrder);
		rear -> Person.ArrivalTime = TempArrival;
                      
		node * temp = new node;
		
	if(rear -> next == NULL || rear -> next == rear)
	{	rear -> next = temp;
		temp -> next = rear;
	}
	else
	{	temp -> next = rear -> next;
		rear -> next = temp;
		rear = temp;	
	}
	count += count;
	return count;
}

//Deletes a customer node upon request
int Queue :: Dequeue ()
{	if(!rear)
	  return 0;
	if(rear -> next == rear)
	{	delete rear;
		rear = NULL;
	}
	else
	{	node * temp = rear -> next;
		rear -> next = temp -> next;
		delete temp;
	}
	
}

//Checks to see if the data in rear is NULL and if so state it is empty `
int Queue :: IsEmpty()
{	if(!(rear -> Person.Name) && !(rear -> Person.Order) && !(rear -> Person.ArrivalTime))
	  return 1;
	  
	else
	  return 0;
	
}

//Receives the count value from Enqueue as nodes are added on, so it has a 
//count of the people currently in line 
int Queue :: Count()
{	//int count = Enqueue(TempName,TempOrder, TempArrival);
	//return count;
}
