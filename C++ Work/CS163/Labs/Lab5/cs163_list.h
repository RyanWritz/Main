//list.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    node * previous;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
/* These are the functions you will be implementing for this lab */
int insert_after(node * & head);
int insert_before(node * & head);
int display_last_two(node * head);
int remove_last_two(node * & head);

//challenge:
bool same_length(node * head1, node * head2);
