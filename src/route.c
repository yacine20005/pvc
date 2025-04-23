#include "route.h"
#include <string.h>

Route init_route()
{
    Route route;
    route.size = 0;
    return route;
}

RouteCollection init_route_collection()
{
    RouteCollection collection;
    collection.size = 0;
    return collection;
}

int add_route_to_collection(RouteCollection *collection, Route route)
{
    if (collection == NULL || collection->size >= CYCLE_SIZE)
        return -1;

    collection->paths[collection->size] = route;
    collection->size++;
    return 0;
}



