#include "cs163_list.h"

/* These are the functions you will be implementing */
/* USE RECURSION! */
int insert_after(node * & head)
{   if(!head)
        return 0;
    if(head -> data == 2)
    {   node * temp = new node;
        temp -> next = head -> next;
        head -> next -> previous = temp;
        head -> next = temp;
        temp -> previous = head;
    }
    return insert_after(head -> next); 
}


int insert_before(node * & head)    
{   int total = 1;
    
    if(!head)
    return 0;

    total = insert_before(head -> next) + 1;
    

    if(head -> data == 2)
    {   node * temp = new node;
        temp -> next = head;
        head -> previous = temp;
        temp -> previous = head -> previous;
        head = temp;
        ++total; 
    }
     return total;
}

int display_last_two(node * head)
{  
}
int remove_last_two(node * & head)
{

}


//challenge:
bool same_length(node * head1, node * head2)
{

}

