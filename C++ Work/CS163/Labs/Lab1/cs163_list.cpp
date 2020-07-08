#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{  /* node * current = head;
    int sumtotal;

    if(!head)
        return 0;

    sumtotal = head-> data;

    while( current -> next != NULL)
        {   current = current -> next;
            sumtotal += current -> data;
        }
    cout << "the total sum is " << sumtotal << endl;
    
*/	//Step 1 - Write your code here
    cout << "The total sum is " <<  sum_total(head) << endl;
    
}

//Now implement the function recursively!
int list::sum_total(node * head)
{   if (!head)
        return 0;
    return head -> data + sum_total(head -> next);

}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{   node * current = head; 
    if(!head)
        return 0;
    if(head -> next == NULL) 
    {   delete head;
        head -> next = NULL;
    }
    else 
    {      while(current -> next != NULL)
        {       tail = current;
                current = current -> next;
        }
           delete current;
           current -> next = NULL;
           tail -> next = NULL;
    }
       //Step 2 - Write your code here

}

//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{   if(!head)
        return 0;
        

}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{   node * current = head;

    if(!head)
        return 0;
    if( head -> next == NULL)
    {   delete head;
        head -> next = NULL;
    }
    else 
    {   while(current != NULL) 
           delete head;
           head = NULL;
           head = current;
    }
       //Step 3 - Remove all nodes in a LLL

}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{


}


// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
        //Step 4 - Write your code here

}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{


}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
        //Step 5 - Write your code here

}

//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{


}
