#ifndef CITY_H
#define CITY_H

#include <stdio.h>
#include <stdlib.h>

#define CITY_SIZE 100

typedef struct
{
    char name[50];
    int x;
    int y;
} City;

typedef struct
{
    City cities[CITY_SIZE];
    int size;
} Map;

/**
 * @brief Initialize the array of cities
 *
 * @return Map* The pointer to the array of cities
 */
Map *init_map();

#endif // CITY_H