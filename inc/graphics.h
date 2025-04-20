#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <MLV/MLV_all.h>
#include "city.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

/**
 * @brief Displays the map with city names and coordinates in the console
 *
 * @param map The map containing cities to display
 */
void print_map(Map map);

/**
 * @brief Displays the map inline with city names followed by the total distance
 *
 * @param map The map containing cities to display
 */
void print_map_inline(Map map);

/**
 * @brief Displays a list of maps in the console
 *
 * @param lst The list of maps to display
 */
void print_list_map(MapList lst);

/**
 * @brief Displays the cities of a map in an MLV window
 *
 * @param map The map containing cities to display
 * @param x_offset Horizontal offset for display
 * @param y_offset Vertical offset for display
 */
void MLV_print_cities(Map map, int x_offset, int y_offset);

/**
 * @brief Draws the path between cities of a map in an MLV window
 *
 * @param map The map containing the path to draw
 * @param color The color of the path
 * @param x_offset Horizontal offset for display
 * @param y_offset Vertical offset for display
 */
void MLV_print_path(Map map, MLV_Color color, int x_offset, int y_offset);

/**
 * @brief Displays a list of paths in an MLV window with different shades of red
 *
 * @param lst The list of maps containing paths to display
 * @param x_offset Horizontal offset for display
 * @param y_offset Vertical offset for display
 */
void MLV_print_list_map(MapList lst, int x_offset, int y_offset);

/**
 * @brief Displays the complete world with cities and paths in an MLV window
 *
 * @param lst The list of maps to display
 */
void MLV_print_world(MapList lst);

#endif // GRAPHICS_H