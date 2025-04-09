#include "city.h"
Map *init_map()
{
    Map *map = malloc(sizeof(Map));
    if (map == NULL)
    {
        perror("Error allocating memory for city list");
        return NULL;
    }
    map->size = 0;
    return map;
}