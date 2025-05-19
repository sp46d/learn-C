// Exercise 3.63. Write a version of Program 3.16 that handles three-dimensional
// arrays.
#include <stdio.h>
#include <stdlib.h>

int*** malloc3d(int x, int y, int z)
{
    int*** out = malloc(x * sizeof(int**));
    for (int i = 0; i < x; i++) {
        out[i] = malloc(y * sizeof(int*));
        for (int j = 0; j < y; j++) {
            out[i][j] = malloc(z * sizeof(int));
        }
    }
    return out;
}

int main(int argc, char* argv[])
{
    int dimx = atoi(argv[1]);
    int dimy = atoi(argv[2]);
    int dimz = atoi(argv[3]);
    int*** data3d = malloc3d(dimx, dimy, dimz);
    int cnt = 0;
    for (int i = 0; i < dimx; i++) {
        for (int j = 0; j < dimy; j++) {
            for (int k = 0; k < dimz; k++) {
                data3d[i][j][k] = cnt;
                cnt++;
            }
        }
    }
    for (int i = 0; i < dimx; i++) {
        for (int j = 0; j < dimy; j++) {
            for (int k = 0; k < dimz; k++) {
                printf("%d ", data3d[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}