#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "chocolate_factory.h"

#define MAX_CANDIES 100

Candy assembly_line[MAX_CANDIES]; // Assembly line (bounded buffer) to store candies
int in = 0; // Index to add candies to the assembly line
int out = 0; // Index to remove candies from the assembly line
int candy_count = 0; // Number of candies currently on the assembly line

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for synchronizing access to the assembly line

void *oompa_loompa(void *arg) {
    int candies_to_produce = *((int *)arg); // Number of candies this Oompa Loompa will produce
    int candy_produced = 0;

    // Predefined list of colors for each Oompa Loompa
    char *colors[] = {"AliceBlue", "PeachPuff", "Chocolate", "LemonChiffon", "Crimson", "CornflowerBlue", "Gold", "HotPink", "LightSeaGreen", "Lavender"};

    // Select color for this Oompa Loompa based on its thread ID
    int color_index = pthread_self() % (sizeof(colors) / sizeof(colors[0]));
    char *color = colors[color_index];

    while (candy_produced < candies_to_produce) {
        // Produce candy
        Candy new_candy;
        asprintf(&new_candy.color, "%s%d", color, candy_produced + 1); 
        new_candy.number = candy_produced + 1;

        // Wait if assembly line is full
        while (candy_count >= MAX_CANDIES) {
            sleep(1); // Wait for 1 second before checking again
        }

        // Add candy to the assembly line
        pthread_mutex_lock(&mutex);
        assembly_line[in] = new_candy;
        in = (in + 1) % MAX_CANDIES;
        candy_count++;
        
        printf("Oompa Loompa %lu produced a %s candy with number %d\n", pthread_self(), new_candy.color, new_candy.number);

        candy_produced++;
        pthread_mutex_unlock(&mutex);

        
    }

    pthread_exit(NULL);
}

