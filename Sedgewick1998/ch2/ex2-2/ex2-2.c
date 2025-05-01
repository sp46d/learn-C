#include <stdio.h>
#include <time.h>

int main(void)
{
    int i, j, k, count = 0;
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                count++;

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Counting to %d takes %g seconds.\n", count, cpu_time_used);

    return 0;
}
