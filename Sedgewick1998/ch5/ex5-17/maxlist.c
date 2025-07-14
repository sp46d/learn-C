// Exercise 5.17
// Write a recursive program that finds the maximum element in a linked list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int item;
    struct node* next;
} Node;

Node* NEW(int item, Node* next)
{
    // helper function that creates a new node
    Node* new = malloc(sizeof(*new));
    new->item = item;
    new->next = next;
    return new;
}

Node* createlist(int len)
{
    // creates a list of size len with a random number generated for each node
    srand(time(NULL));
    int item = rand() % 100;
    Node* head = NEW(item, NULL);
    for (int i = 1; i < len; i++) {
        item = rand() % 100;
        head = NEW(item, head);
    }
    return head;
}

int findmax(Node* l)
{
    // finds maximum item in the linked list that starts from the give node l.
    // The algorithm used here finds the maximum value by comparing the item in
    // the first node against the maximum value from the rest of the nodes
    // recursively.
    int firstelem = l->item;
    if (l->next == NULL) {
        return firstelem;
    }
    int maxrest = findmax(l->next);
    return firstelem > maxrest ? firstelem : maxrest;
}

int main(int argc, char* argv[])
{
    int N = atoi(argv[1]);
    Node* mylist = createlist(N);
    Node* t;
    printf("List (0-99):\n");
    printf(">");
    for (t = mylist; t != NULL; t = t->next) {
        printf(" %d", t->item);
    }
    printf("\n");
    printf("\nMax number:\n");
    printf("> %d\n", findmax(mylist));

    return 0;
}