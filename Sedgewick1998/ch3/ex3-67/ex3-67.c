// Exercise 3.67. Write a program to convert a sparse matrix from a
// two-dimensional array to a multilist with nodes for only nonzero values.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20 // number of rows
#define M 20 // number of columns

typedef struct node* link;

typedef struct {
    int row;
    int col;
    int value;
} Item;

struct node {
    enum { ITEM, HEADER } tag;
    union {
        Item item;
        int header;
    } u;
    link right;
    link down;
};

int main(void)
{
    // create a sparse matrix
    int a[N][M];
    int cnt = 0;
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = (1.0 * rand() / RAND_MAX) > 0.1 ? 0 : i * 100 + j;
            if (a[i][j]) {
                cnt++;
            }
        }
    }

    // a head node that contains total number of rows and columns and the number
    // of non-zero values
    link head = malloc(sizeof(*head));
    head->tag = ITEM;
    head->u.item.row = N;
    head->u.item.col = M;
    head->u.item.value = cnt;
    head->down = NULL;
    head->right = NULL;

    // create a header list for each row and column
    link r_header = head;
    for (int i = 0; i < N; i++) {
        r_header = (r_header->down = malloc(sizeof(*r_header)));
        r_header->tag = HEADER;
        r_header->u.header = i;
        r_header->right = r_header;
        r_header->down = NULL;
    }
    link c_header = head;
    for (int i = 0; i < M; i++) {
        c_header = (c_header->right = malloc(sizeof(*c_header)));
        c_header->tag = HEADER;
        c_header->u.header = i;
        c_header->right = NULL;
        c_header->down = c_header;
    }

    // create nodes for non-zero values in matrix
    int n;
    link t;
    link r = head;
    link c;
    for (int i = 0; i < N; i++) {
        r = r->down;
        c = head;
        for (int j = 0; j < M; j++) {
            c = c->right;
            n = a[i][j];
            if (n) {
                t = malloc(sizeof(*t));
                t->tag = ITEM;
                t->u.item.row = i;
                t->u.item.col = j;
                t->u.item.value = n;
                t->right = r->right;
                t->down = c->down;

                r->right = t;
                c->down = t;
            }
        }
    }

    // When I print out the result as below, I realized that this linked list
    // could have been done via only either row or column headers.
    //
    // What's the benefit of maintaining both column and row headers?
    // Maybe because I can access its elements from both directions? Which
    // provides more convinient manipulation of the list? Think about it.
    int cnt_list = 0;
    for (link r = head->down; r != NULL; r = r->down) {
        for (link t = r->right; t != r; t = t->right) {
            printf("%d ", t->u.item.value);
            cnt_list++;
        }
    }
    printf(" => total %d non-zero values\n\n", cnt_list);

    // print the sparse matrix as an array for comparison
    printf("(%d non-zero values) a[][] = \n", cnt);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
