#include "graphics.h"

void print_map(Map map)
{
    for (int i = 0; i < map.size; i++)
    {
        printf("City: %s, Coordinates: (%d, %d)\n", map.cities[i].name, map.cities[i].x, map.cities[i].y);
    }
}