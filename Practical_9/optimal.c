#include <stdio.h>

int main() {
    int frames = 3;
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12;

    int memory[3];
    int i, j, k;
    int hit = 0, fault = 0;

    // Initialize
    for(i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check HIT
        for(j = 0; j < frames; j++) {
            if(memory[j] == pages[i]) {
                hit++;
                found = 1;
                break;
            }
        }

        // If FAULT
        if(!found) {
            int index = -1, farthest = i + 1;

            for(j = 0; j < frames; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(memory[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }

                // If page not found in future
                if(k == n) {
                    index = j;
                    break;
                }
            }

            // If all pages will be used soon
            if(index == -1) index = 0;

            memory[index] = pages[i];
            fault++;
        }
    }

    printf("Total Hits = %d\n", hit);
    printf("Total Faults = %d\n", fault);

    float hit_per = (float)hit / n * 100;
    float fault_per = (float)fault / n * 100;

    printf("Hit Percentage = %.2f%%\n", hit_per);
    printf("Fault Percentage = %.2f%%\n", fault_per);

    return 0;
}
