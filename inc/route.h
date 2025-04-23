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
} Route;

typedef struct
{
    Route paths[CYCLE_SIZE];
    int size;
} RouteCollection;

/**
 * @brief Initialize the RouteCollection
 *
 * @return RouteCollection* The pointer to the RouteCollection
 */
Route *init_route();

/**
 * @brief Initialize the RouteCollection
 *
 * @return RouteCollection* The pointer to the RouteCollection
 */
RouteCollection *init_route_collection();

/**
 * @brief Add a route to the collection of routes
 *
 * @param route_collection The collection of routes
 * @param route The route to add
 * @return int 0 if success, -1 if failure
 */
int add_route_to_collection(RouteCollection *, Route);

#endif // CITY_H