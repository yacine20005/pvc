#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <MLV/MLV_all.h>
#include "route.h"
#define WINDOW_WIDTH 2600
#define WINDOW_HEIGHT 1200

/**
 * @brief Displays the route with city names and coordinates in the console
 *
 * @param route The route containing cities to display
 */
void print_map(Route route);

/**
 * @brief Displays the route inline with city names followed by the total distance
 *
 * @param route The route containing cities to display
 */
void print_map_inline(Route route);

/**
 * @brief Displays a collection of routes in the console
 *
 * @param collection The collection of routes to display
 */
void print_list_map(RouteCollection collection);

/**
 * @brief Gets the minimum and maximum coordinates of a list of cities
 *
 * @param route The route to analyze
 * @param min_max An array to store the min and max coordinates
 */
void get_min_max_coordinate(Route, int*);

/**
 * @brief Calculates the scale factor for the x-axis based on the coordinates of cities
 *
 * @param min_x Minimum x-coordinate of the cities
 * @param max_x Maximum x-coordinate of the cities
 * @param width Width of the display area
 * @return int The scale factor for the x-axis
 */
int calculate_scale_x(int, int, int);

/**
 * @brief Calculates the scale factor for the y-axis based on the coordinates of cities
 *
 * @param min_y Minimum y-coordinate of the cities
 * @param max_y Maximum y-coordinate of the cities
 * @param height Height of the display area
 * @return int The scale factor for the y-axis
 */
int calculate_scale_y(int, int, int);

/**
 * @brief Displays the cities of a route in an MLV window
 *
 * @param route The route containing cities to display
 * @param scale_x Scale factor to apply to x coordinates
 * @param scale_y Scale factor to apply to y coordinates
 */
void MLV_print_cities(Route, int, int);

/**
 * @brief Draws the path between cities of a route in an MLV window
 *
 * @param route The route containing the path to draw
 * @param color The color of the path
 * @param scale_x Scale factor to apply to x coordinates
 * @param scale_y Scale factor to apply to y coordinates
 */
void MLV_print_path(Route, MLV_Color, int, int);

/**
 * @brief Displays a collection of paths in an MLV window with different shades of red
 *
 * @param collection The collection of routes containing paths to display
 * @param scale_x Scale factor to apply to x coordinates
 * @param scale_y Scale factor to apply to y coordinates
 */
void MLV_print_list_map(RouteCollection collection, int scale_x, int scale_y);

/**
 * @brief Displays the complete world with cities and paths in an MLV window
 *
 * @param collection The collection of routes to display
 */
void MLV_print_world(RouteCollection collection);



#endif // GRAPHICS_H