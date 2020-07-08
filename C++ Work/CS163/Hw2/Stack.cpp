//Ryan W. Writz (c) 2015
//CS163 HW#2
//This Stack class serves to store the average and current wait times of those who
//have or are in line and have order at the food cart. The data is periodically updated
//when someone tells the program that they have gotten their food and at what time.
//Upon the order being finished, the stack gets the difference of the two times as a 
//current wait time and compares it to the past current times to gain a new average 
//and push the new data on to the stack.

#include "HW2.h"

//The constructor of the stack, sets head to NULL and starts the top_index at the top
//of the array
Stack :: Stack()
{	head = NULL;
	top_index = 0;
}

//The destructor of the stack, deletes the stack and its data if it exists
Stack :: ~Stack()
{	if(head)
		{delete [] head -> CurrentWait;
		delete [] head -> AverageWait;
		delete head;
		}		
}

//Checks to see if a stack exists and if so displays what is at the top_index
int Stack :: peek()
{	int Empty = IsEmpty();
	if(Empty == 1)
          return 0;
	else
	   { cout << head -> CurrentWait;
	     cout << head -> AverageWait;
	   }
}

//Adds information to push onto the stack and increments the top_index to 
//progress in the array 
int Stack :: push()
{	int count =0;

	if(!head)
	{	head = new TimeStat;
		head -> next = NULL;
		head -> CurrentWait = new int[TIMES];
		head -> AverageWait = new int[TIMES];
         	 top_index = 0;
	}
  
        if(top_index ==  TIMES - 1)
        {  TimeStat * temp = new TimeStat;
	   temp -> CurrentWait = new int[TIMES];
	   temp -> AverageWait = new int[TIMES];
           temp -> next = head;
           head = temp;
           --top_index;
        }
 
        //head -> CurrentWait[top_index].copy_entry(to_add);
        //head -> AverageWait[top_index].copy_entry(to_add);
        ++top_index;
	++count;

	return count;
}

//Pops data off of the stack in order to delete it and decrements 
//the top_index as to preserve the array for as long as possible
int Stack :: pop()
{	if(!head)
	   return 0;
 
      if(!top_index)
        { if(head -> next != NULL)
          { TimeStat * temp = head -> next;
 
          delete [] head -> CurrentWait;
	  delete [] head -> AverageWait;
          delete head;
          head  = temp;
          }
  
        }
      else
        --top_index;
	
}

//Calls upon the peek and pop function together to continually
//display the data of the stack till there is none left 
int Stack :: display()
{	while(!head)
	 {   peek();
              pop();
	 }
}

//Checks to see if stack is empty and returns 1 if so.
int Stack :: IsEmpty()
{	int count = push();
	if(count == 0)
		return 1;
	else 
		return 0;	

}
