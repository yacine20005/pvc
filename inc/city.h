#ifndef CITY_H
#define CITY_H

#include <stdio.h>
#include <stdlib.h>

#define CITY_SIZE 100
#define CYCLE_SIZE 128
#define MUTATION_SIZE CYCLE_SIZE / 3
#define BEST_SIZE CYCLE_SIZE / 3
#define RANDOM_SIZE CYCLE_SIZE / 3

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
} Route; // Renommé de Map à Route pour mieux représenter un parcours

typedef struct
{
    Route paths[CYCLE_SIZE]; // Renommé de path à paths et Map à Route
    int size;
} RouteCollection; // Renommé de MapList à RouteCollection pour plus de clarté

/**
 * @brief Initialize the array of cities
 *
 * @return Route* The pointer to the array of cities
 */
Route *init_map();

/**
 * @brief Initialize the RouteCollection
 *
 * @return RouteCollection* The pointer to the RouteCollection
 */
RouteCollection *init_map_list();

/**
 * @brief Add a route to the collection of routes
 *
 * @param route_collection The collection of routes
 * @param route The route to add
 * @return int 0 if success, -1 if failure
 */
int add_map_to_list(RouteCollection *, Route);

#endif // CITY_H