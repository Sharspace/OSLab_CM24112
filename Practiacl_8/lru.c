#include <stdio.h>

int main() {
    int frames = 3;
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12;

    int memory[3];
    int time[3];
    int i, j;
    int hit = 0, fault = 0;
    int counter = 0;

    // Initialize memory
    for(i = 0; i < frames; i++) {
        memory[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check HIT
        for(j = 0; j < frames; j++) {
            if(memory[j] == pages[i]) {
                hit++;
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        // If FAULT
        if(!found) {
            int lru_index = 0;

            for(j = 1; j < frames; j++) {
                if(time[j] < time[lru_index]) {
                    lru_index = j;
                }
            }

            memory[lru_index] = pages[i];
            counter++;
            time[lru_index] = counter;
            fault++;
        }
    }

    printf("Total Hits = %d\n", hit);
    printf("Total Faults = %d\n", fault);

    float hit_ratio = (float)hit / n * 100;
    float fault_ratio = (float)fault / n * 100;

    printf("Hit Percentage = %.2f%%\n", hit_ratio);
    printf("Fault Percentage = %.2f%%\n", fault_ratio);

    return 0;
}
