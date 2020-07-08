#include "cs163_table.h"
using namespace std;

int table::HashFunction(char * key_value, int size)
{   int TotalIndexed = 0;
    unsigned int i = 0;

    for(i; i < strlen(key_value); ++i)
            TotalIndexed += key_value[i];

    cout << TotalIndexed % size;
    return TotalIndexed % size;
}

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the hash table and initialize each
      //element and data member.
    hash_table = new node *[size];
    
    hash_table_size = size;
    int j = 0;
    while( j < size)
    {   hash_table[j] = NULL;
        ++j;
    }

}

//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{
   int Index = HashFunction(key_value,hash_table_size); 
   
    node * temp = new node;

    temp -> entry.copy_entry(to_add);
    temp -> next = hash_table[Index];
    hash_table[Index] = temp;

    //Place your code here

}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{

        //Place your code here

}
