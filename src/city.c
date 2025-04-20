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

MapList *init_map_list()
{
    MapList *map_list = malloc(sizeof(MapList));
    if (map_list == NULL)
    {
        perror("Error allocating memory for city list");
        return NULL;
    }
    map_list->size = 0;
    return map_list;
}

int add_map_to_list(MapList *map_list, Map map)
{
    if (map_list->size >= CYCLE_SIZE)
        return -1;
    map_list->path[map_list->size] = map;
    map_list->size++;
    return 0;
}