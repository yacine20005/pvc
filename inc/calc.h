#ifndef CALC_H
#define CALC_H
#include "city.h"
#include <math.h>

/**
 * @brief To calculate the distance between two points
 *
 * @param x1 the x coordinate of the first point
 * @param y1 the y coordinate of the first point
 * @param x2 the x coordinate of the second point
 * @param y2 the y coordinate of the second point
 * @return float the distance between the two points
 */
float calc_distance(int x1, int y1, int x2, int y2);

/**
 * @brief To calculate the entire distance of a path
 *
 * @param map
 * @return float
 */
float calc_distance_array(Map map);

/**
 * @brief Take a populated map and return a shuffled map to create a patj
 *
 * @param size the size of the map
 * @return Map with a shuffled path trought all the cities
 */
Map generate_random_path(Map map, int size);

/**
 * @brief Function to swap two group of cities
 *
 * @param map the map where to swap the cities
 * @param first_group the first index of the first group
 * @param second_group the first index of the second group
 * @param size the size of the two groups
 * @return Map the map with the two groups swapped
 */
Map swap_cities(Map map, int first_group, int second_group, int size);

/**
 * @brief Generate a mutation of the map
 *
 * @param map the path to mutate from
 * @param size the size of the map
 * @return Map the mutated map
 */
Map mutate(Map map, int size);

/**
 * @brief To compare two maps
 *
 * @param a the first map to compare
 * @param b the second map to compare
 * @return int 1 if a is shorter than b, 0 otherwise, and -1 if they are not the same size
 */
int map_comparison(const void *a, const void *b);

#endif // CALC_H
