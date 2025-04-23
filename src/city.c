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

int create_initial_RouteCollection(RouteCollection *collection, Route *cities, int size)
{
    if (collection == NULL || cities == NULL || size <= 0)
        return -1;
    for (int i = 0; i < size; i++)
    {    
        if(add_map_to_list(collection, generate_random_path(*cities, size)) == -1)
        {
            printf("Error: Creation of initial RouteCollection failed\n");
            return -1;
        }
    }
    return 0;
}

Route generate_random_path(Route route, int size)
{
    Route shuffled_route = route;
    City temp;
    for (int i = 0; i < size; i++)
    {
        int random_index = rand() % size;
        temp = shuffled_route.cities[i];
        shuffled_route.cities[i] = shuffled_route.cities[random_index];
        shuffled_route.cities[random_index] = temp;
    }
    return shuffled_route;
}