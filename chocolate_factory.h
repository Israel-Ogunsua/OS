#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#ifndef CHOCOLATE_FACTORY_H
#define CHOCOLATE_FACTORY_H


extern int in;
extern int out;
extern int candy_count;

typedef struct {
    char* color;
    int number;
} Candy;

void *oompa_loompa(void *arg);
void *child(void *arg);

extern pthread_mutex_t mutex; // Declare mutex as extern
#endif

