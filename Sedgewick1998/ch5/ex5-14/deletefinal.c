#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* next;
} Node;

Node* deletefinal(Node* x)
{
    if (x == NULL) {
        return NULL;
    }
    if (x->next == NULL) {
        // we are at the final node
        Node* t = x->next;
        free(x);
        return t;
    }
    x->next = deletefinal(x->next);
    return x;
}

Node* createlist(int n)
{
    Node* first = malloc(sizeof(*first));
    first->item = 0;
    first->next = NULL;
    Node* t;
    Node* new;
    for (int i = 1; i < n; i++) {
        new = malloc(sizeof(*new));
        new->item = i;
        new->next = NULL;
        for (t = first; t->next != NULL; t = t->next)
            ;
        t->next = new;
    }
    return first;
}

void showlist(Node* x)
{
    printf(">");
    Node* t;
    for (t = x; t != NULL; t = t->next) {
        printf(" %d", t->item);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./deletefinal <NUMBER>\n");
        exit(1);
    }

    int N = atoi(argv[1]);
    Node* mylist = createlist(N);
    showlist(mylist);
    deletefinal(mylist);
    showlist(mylist);
    deletefinal(mylist);
    showlist(mylist);
}