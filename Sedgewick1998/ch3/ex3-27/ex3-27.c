// Exercise 3.27 Given pointers x and t to nodes on a circular list, write a
// code fragment that moves the node following t to the position following the
// node following x on the list.

#include "../linkedlist.h"
#include <stdio.h>

int main(void)
{
    // create a circular list with 20 nodes.
    link list = createlist(20, 1);

    // suppose that x is 3rd node and y is 10th node on the list
    link x = findnode(list, 2);
    link t = findnode(list, 9);

    // Move the node (t1) following t to the position (x1) following the node
    // following x on the list
    link t1 = t->next;
    deletenode(list, t1);

    link x1 = x->next;
    insertnode(x1, t1, 1);

    // after the node shift, the resulting list should look like:
    // expect: 1, 2, 3, 4, 11, 5, 6, 7, 8, 9, 10, 12, 13, 14, ..., 20
    printnodes(list);
    return 0;
}