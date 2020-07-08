#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{      
    q_node * temp = new q_node;
    temp -> entry.copy_entry(to_add);

    if(temp -> entry.copy_entry(to_add) == 0)
    {   delete temp;
        temp = NULL;
        return 0;
    }

    if(!rear)
    {    temp -> next = temp;
         rear = temp; 
    }
    if(rear -> next == NULL)
    {    temp -> next = rear;
         rear -> next = temp;
    }
    else 
    {   temp -> next = rear -> next;
        rear -> next = temp;
        rear = temp;
        
    }
        //Write the function here
}

//Remove the node at the front
int queue::dequeue ()
{   
    if(!rear)
        return 0;
    if(rear -> next == rear)
    {   delete rear;
        rear = NULL;
    }
    else
    {       q_node * temp = rear -> next;
            rear -> next = temp -> next;
            delete temp;
            
    }
	//Write the function here
}

