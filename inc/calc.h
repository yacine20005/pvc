#ifndef CALC_H
#define CALC_H
#include "city.h"
#include <math.h>

/**
 * @brief return the maximum x coordinate of a map
 *
 * @param map map full of cities
 * @return int maximum x coordinate
 */
int max_x_map(Map);

/**
 * @brief return the maximum y coordinate of a map
 *
 * @param map map full of cities
 * @return int maximum y coordinate
 */
int max_y_map(Map);

/**
 * @brief Evolves a list of maps by applying mutations and generating new random paths.
 *
 * This function performs evolution on the provided map list through two steps:
 * 1. Mutates maps in the list (excluding the first and last MUTATION_SIZE elements)
 * 2. Generates completely new random paths for a portion of the list
 * 3. Sorts the resulting list based on map comparison criteria
 *
 * @param list Pointer to the MapList to evolve
 * @return 0 on success, -1 if the list is NULL or empty
 */
int evolve_list_map(MapList *);

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
 * @param map
 * @return float
 */
float calc_distance_array(Map);

/**
 * @brief Take a populated map and return a shuffled map to create a path
 *
 * @param size the size of the map
 * @return Map with a shuffled path trought all the cities
 */
Map generate_random_path(Map, int);

/**
 * @brief Function to swap two group of cities
 *
 * @param map the map where to swap the cities
 * @param first_group the first index of the first group
 * @param second_group the first index of the second group
 * @param size the size of the two groups
 * @return Map the map with the two groups swapped
 */
Map swap_cities(Map, int, int, int);

/**
 * @brief Generate a mutation of the map
 *
 * @param map the path to mutate from
 * @param size the size of the map
 * @return Map the mutated map
 */
Map mutate(Map, int);

/**
 * @brief To compare two maps
 *
 * @param a the first map to compare
 * @param b the second map to compare
 * @return int 1 if a is longer than b, 0 otherwise, and -1 if they are not the same size
 */
int map_comparison(const void *, const void *);

#endif // CALC_H
