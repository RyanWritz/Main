#include "cs163_stack.h"


//These are the functions you will be implementing
//for this lab, using a linear linked list of arrays
//as the data structure

//Add a new item to the top of stack
int stack::push(const journal_entry & to_add)
{   if(!head)
    { head = new node;
      head -> entries = new journal_entry[MAX];
      head -> next = NULL;
      top_index = 0;
    } 

    if(top_index ==  MAX - 1)
    { node * temp = new node;
       temp -> entries = new journal_entry[MAX];
       temp -> next = head;
       head = temp;
       --top_index;
    }
    
    head -> entries[top_index].copy_entry(to_add);
    ++top_index;
    //Implement the function here
}

//Remove the top of stack
int stack::pop (void)
{ if(!head)
    return 0;
 
  if(!top_index)
    { if(head -> next != NULL)
      { node * temp = head -> next;
      
      delete [] head -> entries; 
      delete head;
      head  = temp;
      }

    }
  else
         --top_index;
    
  //Implement the function here

}

//Supply the journal at the top of stack back to the client
//Return 0 if there are no items
//top_index is one beyond where the top of stack is...
//with no items, top_index is zero
int stack::peek(journal_entry & found_at_top) const
{   if(!head)
        return 0;

    else
     {      
     }
    //Implement the function here
}

