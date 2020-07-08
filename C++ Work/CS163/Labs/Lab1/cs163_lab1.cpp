#include "cs163_list.h"
using namespace std;

int main()
{   node * head;
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    my_list.build();
    my_list.display_all();

    //PLACE YOUR FUNCTION CALL HERE!
    // mylist.remove_all();
    my_list.remove_last();
    my_list.display_all();
    my_list.sum_total();
    
    return 0;    
}
