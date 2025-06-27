#include "item.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./main <NUMBER>\n");
        exit(1);
    }
    int N = atoi(argv[1]);

    srand(time(NULL));
    Q queues[M];
    for (int i = 0; i < M; i++) {
        queues[i] = QUEUEinit(N);
    }
    for (int i = 0; i < N; i++) {
        QUEUEput(queues[rand() % M], i);
    }
    int cnt;
    for (int i = 0; i < M; i++) {
        printf("%3d items: ", QUEUEcount(queues[i]));
        for (cnt = 0; !QUEUEempty(queues[i]); cnt++) {
            printf("%3d ", QUEUEget(queues[i]));
        }
        printf("\n");
    }
    for (int i = 0; i < M; i++) {
        QUEUEdestroy(queues[i]);
    }
    return 0;
}
