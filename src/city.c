#include "city.h"
#include <string.h>

Route *init_map()
{
    Route *route = (Route *)malloc(sizeof(Route));
    if (route == NULL)
    {
        printf("Error: malloc failed\n");
        return NULL;
    }
    route->size = 0;
    return route;
}

RouteCollection *init_map_list()
{
    RouteCollection *collection = (RouteCollection *)malloc(sizeof(RouteCollection));
    if (collection == NULL)
    {
        printf("Error: malloc failed\n");
        return NULL;
    }
    collection->size = 0;
    return collection;
}

int add_map_to_list(RouteCollection *collection, Route route)
{
    if (collection == NULL || collection->size >= CYCLE_SIZE)
        return -1;

    collection->paths[collection->size] = route;
    collection->size++;
    return 0;
}