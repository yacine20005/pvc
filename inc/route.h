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

/**
 * @brief Create the initial RouteCollection with random routes
 *
 * @param collection The collection of routes
 * @param cities The array of cities
 * @param size The size of the array of cities
 * @return int 0 if success, -1 if failure
 */
int create_initial_RouteCollection(RouteCollection *, Route *, int);

/**
 * @brief Take a populated route and return a shuffled route to create a path
 *
 * @param size the size of the route
 * @return Route with a shuffled path through all the cities
 */
Route generate_random_path(Route, int);

#endif // CITY_H