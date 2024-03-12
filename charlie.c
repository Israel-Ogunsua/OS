#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "chocolate_factory.h"

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <oompa_loompas> <children> <assembly_line_size> <candies_per_box> <candies_per_oompa>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    int num_oompa_loompas = atoi(argv[1]);
    int num_children = atoi(argv[2]);
    int assembly_line_size = atoi(argv[3]);
    int candies_per_box = atoi(argv[4]);
    int candies_per_oompa = atoi(argv[5]);

    // Initialize assembly line and other variables
    Candy assembly_line[assembly_line_size];
    pthread_t oompa_loompas[num_oompa_loompas];
    pthread_t children[num_children];

    // Create mutex
    pthread_mutex_init(&mutex, NULL);

    // Create Oompa Loompa threads
    for (int i = 0; i < num_oompa_loompas; i++) {
        pthread_create(&oompa_loompas[i], NULL, oompa_loompa, &candies_per_oompa);
    }

    // Create child threads
    for (int i = 0; i < num_children; i++) {
        pthread_create(&children[i], NULL, child, &candies_per_box);
    }

    // Wait for Oompa Loompa threads to finish
    for (int i = 0; i < num_oompa_loompas; i++) {
        pthread_join(oompa_loompas[i], NULL);
    }

    // Wait for children threads to finish (This part of the code will never execute)
    for (int i = 0; i < num_children; i++) {
        pthread_join(children[i], NULL);
    }

    // Cleanup resources
    pthread_mutex_destroy(&mutex);

    return 0;
}

