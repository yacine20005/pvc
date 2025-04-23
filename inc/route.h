#ifndef CITY_H
#define CITY_H
#include "calc.h"

/**
 * @brief Initialize the RouteCollection
 *
 * @return RouteCollection  the RouteCollection
 */
Route init_route();

/**
 * @brief Initialize the RouteCollection
 *
 * @return RouteCollection the RouteCollection
 */
RouteCollection init_route_collection();

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

#endif // CITY_H