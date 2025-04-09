#ifndef CITY_H
#define CITY_H

#include <stdio.h>
#include <stdlib.h>

#define CITY_SIZE 100
#define CYCLE_SIZE 10
#define MUTATION_SIZE 3

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

typedef struct 
{
   Map path[CYCLE_SIZE];
   int size;
} MapList;

/**
 * @brief Initialize the array of cities
 *
 * @return Map* The pointer to the array of cities
 */
Map *init_map();

int add_map_to_list(MapList *list, Map map);

MapList * init_map_list();

#endif // CITY_H