#include <math.h>
#include <stdio.h>

int triangular(int i);
int find_next_triangular(int in);
void find_triplet(int in, int out[]);

int main(void)
{
    // int test_tri_num[] = { 1, 3, 6, 10, 15 };
    // for (int i = 1; i <= sizeof(test_tri_num) / sizeof(test_tri_num[0]); i++)
    // { test of triangular() printf("%2d-th triangular number is: %d", i,
    // triangular(i)); printf("\t<- it should be %d\n", test_tri_num[i - 1]);
    //
    // test of find_next_triangular()
    // printf("Index of smallest triangular number larger than %2d is: %2d",
    //     test_tri_num[i - 1] + 1,
    //     find_next_triangular(test_tri_num[i - 1] + 1));
    // printf("\t<- it should be %d\n", i + 1);
    //
    // test of find_triplet()
    // }
    int low = 1;
    int high = 100;
    int out[3] = { 0 };

    for (int in = low; in <= high; in++) {
        find_triplet(in, out);
        if (out[0] == -1)
            printf("find_triplet(%d) has no solutions\n", in);
        else
            printf(
                "find_triplet(%d) => %d, %d, %d\n", in, out[0], out[1], out[2]);
    }

    return 0;
}

int triangular(int i)
{
    if (i == 0)
        return 0;
    int tri_number = 0;
    for (int num = 1; num <= i; num++) {
        tri_number += num;
    }
    return tri_number;
}

int find_next_triangular(int in)
{
    int i;
    for (i = 1; in >= triangular(i); i++)
        ;
    return i;
}

void find_triplet(int in, int out[])
{
    int max_index = find_next_triangular(in);
    int first, second, third;
    for (int i = 0; i < max_index; i++) {
        first = triangular(i);
        for (int j = 0; j < max_index; j++) {
            second = triangular(j);
            for (int k = 0; k < max_index; k++) {
                third = triangular(k);
                if (first + second + third == in) {
                    out[0] = first;
                    out[1] = second;
                    out[2] = third;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
        out[i] = -1;
    return;
}
