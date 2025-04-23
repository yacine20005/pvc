#ifndef CALC_H
#define CALC_H
#include "route.h"
#include <math.h>

/**
 * @brief return the maximum x coordinate of a map
 *
 * @param route route full of cities
 * @return int maximum x coordinate
 */
int max_x_map(Route);

/**
 * @brief return the maximum y coordinate of a map
 *
 * @param route route full of cities
 * @return int maximum y coordinate
 */
int max_y_map(Route);

/**
 * @brief Execute one iteration of the genetic algorithm
 *
 * @param routes A collection of routes to evolve
 * @param nb_mutation Number of routes to mutate
 * @param nb_best Number of best routes to keep unchanged
 * @param nb_random Number of random routes to generate
 * @return int 0 if successful, -1 otherwise
 */
int genetic_loop(RouteCollection *, int, int, int);

/**
 * @brief To calculate the distance between two points
 *
 * @param x1 the x coordinate of the first point
 * @param y1 the y coordinate of the first point
 * @param x2 the x coordinate of the second point
 * @param y2 the y coordinate of the second point
 * @return float the distance between the two points
 */
float calc_distance(int, int, int, int);

/**
 * @brief To calculate the entire distance of a path
 *
 * @param route
 * @return float
 */
float calc_distance_array(Route);

/**
 * @brief Take a populated route and return a shuffled route to create a path
 *
 * @param size the size of the route
 * @return Route with a shuffled path through all the cities
 */
Route generate_random_path(Route, int);

/**
 * @brief Function to swap two group of cities
 *
 * @param route the route where to swap the cities
 * @param first_group the first index of the first group
 * @param second_group the first index of the second group
 * @param size the size of the two groups
 * @return Route the route with the two groups swapped
 */
Route swap_cities(Route, int, int, int);

/**
 * @brief Generate a mutation of the route
 *
 * @param route the path to mutate from
 * @param size the size of the route
 * @return Route the mutated route
 */
Route mutate(Route, int);

/**
 * @brief To compare two routes
 *
 * @param a the first route to compare
 * @param b the second route to compare
 * @return int -1 if a is shorter than b, 1 if a is longer than b, and 0 if equal, -1 if they are different sizes
 */
int map_comparison(const void *, const void *);

#endif // CALC_H
