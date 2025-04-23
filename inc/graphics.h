#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <MLV/MLV_all.h>
#include "city.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

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
 * @brief Displays the cities of a route in an MLV window
 *
 * @param route The route containing cities to display
 * @param x_offset Horizontal offset for display
 * @param y_offset Vertical offset for display
 */
void MLV_print_cities(Route route, int x_offset, int y_offset);

/**
 * @brief Draws the path between cities of a route in an MLV window
 *
 * @param route The route containing the path to draw
 * @param color The color of the path
 * @param x_offset Horizontal offset for display
 * @param y_offset Vertical offset for display
 */
void MLV_print_path(Route route, MLV_Color color, int x_offset, int y_offset);

/**
 * @brief Displays a collection of paths in an MLV window with different shades of red
 *
 * @param collection The collection of routes containing paths to display
 * @param x_offset Horizontal offset for display
 * @param y_offset Vertical offset for display
 */
void MLV_print_list_map(RouteCollection collection, int x_offset, int y_offset);

/**
 * @brief Displays the complete world with cities and paths in an MLV window
 *
 * @param collection The collection of routes to display
 */
void MLV_print_world(RouteCollection collection);

#endif // GRAPHICS_H