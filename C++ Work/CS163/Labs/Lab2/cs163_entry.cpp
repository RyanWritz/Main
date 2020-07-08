#include "cs163_entry.h"


//Step #2: Implement this function
//This function takes the argument and copies it into
//the journal's data members
int journal_entry::copy_entry(const journal_entry & copy_from)
{   if(!copy_from.title)
        return 0;
    if(title)    
        delete [] title;

    if(notes)
        delete [] notes;

    title = new char[strlen(copy_from.title) +1];
    notes = new char[strlen(copy_from.notes) +1];

    if (title && !notes)
          strcpy(title, copy_from.title);
    if( title && notes)
    {   strcpy(title, copy_from.title);
        strcpy(notes, copy_from.notes); 
    }
    
       //Place your code here
}


//Step #2: Implement this function
//This function will return non-zero if the title sent
//in as an argument matches the data member. It supplies
//the matching journal back as an argument
int journal_entry::retrieve(char * matching_title, journal_entry & found)
{
   if(strcmp(matching_title, title) ==  0)
   {if(found.title)
       delete [] found.title;  
      if(found.notes)
        delete [] found.notes;

    found.title = new char[strlen(title) +1];
    found.notes = new char[strlen(notes) +1];

    strcpy(found.title, title);
    strcpy(found.notes, notes);
    }
   return 1;
      //Place your code here

}

