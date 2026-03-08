#include <stdio.h>

#define MAXP 10
#define MAXR 10

int main() {

    int p, r;
    int allocation[MAXP][MAXR], max[MAXP][MAXR];
    int need[MAXP][MAXR];
    int available[MAXR];
    int finish[MAXP] = {0};
    int safeSeq[MAXP];

    int i, j, k, count = 0;

    printf("Enter number of Processes: ");
    scanf("%d", &p);

    printf("Enter number of Resources: ");
    scanf("%d", &r);

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }

    // Calculate Need Matrix
    for(i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\n---------------- Allocation Matrix ----------------\n");
    for(i = 0; i < p; i++) {
        printf("P%d\t", i);
        for(j = 0; j < r; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }

    printf("\n---------------- Max Matrix ----------------\n");
    for(i = 0; i < p; i++) {
        printf("P%d\t", i);
        for(j = 0; j < r; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }

    printf("\n---------------- Need Matrix ----------------\n");
    for(i = 0; i < p; i++) {
        printf("P%d\t", i);
        for(j = 0; j < r; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources:\n");
    for(i = 0; i < r; i++)
        printf("%d ", available[i]);

    printf("\n");

    // Safety Algorithm
    while(count < p) {
        int found = 0;

        for(i = 0; i < p; i++) {
            if(finish[i] == 0) {

                for(j = 0; j < r; j++) {
                    if(need[i][j] > available[j])
                        break;
                }

                if(j == r) {
                    for(k = 0; k < r; k++)
                        available[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in Safe State!\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE State.\nSafe Sequence: ");
    for(i = 0; i < p; i++)
        printf("P%d ", safeSeq[i]);

    printf("\n");

    return 0;
}
