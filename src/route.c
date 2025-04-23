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

int create_initial_RouteCollection(RouteCollection *collection, Route *cities, int size)
{
    if (collection == NULL || cities == NULL || size <= 0)
        return -1;
    for (int i = 0; i < size; i++)
    {    
        printf("Creating initial RouteCollection: %d\n", i);
        if(add_route_to_collection(collection, generate_random_path(*cities, cities->size)) == -1)
        {
            printf("Error: Creation of initial RouteCollection failed\n");
            return -1;
        }
    }
    qsort(collection->paths, collection->size, sizeof(Route), route_comparison);
    return 0;
}



