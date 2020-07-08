#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>


struct node
{
       int  data;
       node * next;
};

class list
{
      public:
             //I have written these functions for your convenience
             list();
             ~list();
             void build();
             void display_all();
             
             //Write each of these functions Iteratively and Recursively
             int sum_total();		  //Step #1 Iterative
             int sum_total(node * head);  //Step #1 Recursive

	     bool remove_last();          //Step #2 Iterative
             bool remove_last(node * & head, node * & tail);  //Step #2 Recursive

             bool remove_all();                 //Step #3 Iterative
             bool remove_all(node * & head);    //Step #3 Recursive

             bool find_item(int item_to_find);  //Step #4 Iterative
             bool find_item(node * head, int item_to_find);   //Step #4 Recursive

             bool copy(list & from);            //Step #5 Iterative
             bool copy(node * & dest_head, node * & dest_tail, node * source); //Step #5 Recursive

      
      private:
              node * head;
	      node * tail;
};
             
