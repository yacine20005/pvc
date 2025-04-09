#include "graphics.h"

void print_map(Map map)
{
    for (int i = 0; i < map.size; i++)
    {
        printf("City: %s, Coordinates: (%d, %d)\n", map.cities[i].name, map.cities[i].x, map.cities[i].y);
    }
}

void print_map_inline(Map map)
{
    for (int i = 0; i < map.size; i++)
    {
        printf("%s | ", map.cities[i].name);
    }
    printf("\n");
}

void print_list_map(MapList lst){
    for (int i = 0; i < lst.size; i++){
        printf("Path %d: \n", i);
        print_map_inline(lst.path[i]);
        printf("\n");
    }
}