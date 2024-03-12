#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "chocolate_factory.h"

#define MAX_CANDIES 10
extern Candy assembly_line[MAX_CANDIES]; // Declare assembly_line

void *child(void *arg) {
    int candies_per_box = *((int *)arg); // Number of candies per box

    while (1) {
        // Check if enough candies are available to fill a box
        if (candy_count >= candies_per_box) {
            // Consume candies to fill a box
            printf("Child is filling a box of candies:\n");
            printf("Wonka, I have a box of candies containing: ");
            for (int i = 0; i < candies_per_box; i++) {
                pthread_mutex_lock(&mutex);
                Candy consumed_candy = assembly_line[out];
                out = (out + 1) % MAX_CANDIES;
                candy_count--;
                pthread_mutex_unlock(&mutex);

                printf("%s %d", consumed_candy.color, consumed_candy.number);
                if (i < candies_per_box - 1) {
                    printf(", ");
                } else {
                    printf("\n");
                }
            }
            printf("\n");
        }
        // Sleep for a short time before checking the assembly line again
        usleep(500000); // 0.5 second
    }

    pthread_exit(NULL);
}
