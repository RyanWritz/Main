
#include "cs163_list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //insert_after(head);
    int total = insert_before(head);
    display(head);
    cout << "The total number of nodes is " << total << endl;
    
    return 0;
}
