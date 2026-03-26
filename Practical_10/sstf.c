#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = 8;
    int visited[8] = {0};
    int head = 53;
    int total = 0;

    printf("Sequence of Head Movement:\n");

    for(int i = 0; i < n; i++) {
        int min = 1000;
        int index = -1;

        for(int j = 0; j < n; j++) {
            if(visited[j] == 0) {
                int dist = abs(head - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        printf("%d -> %d (distance = %d)\n", head, req[index], min);

        total += min;
        head = req[index];
        visited[index] = 1;
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}

