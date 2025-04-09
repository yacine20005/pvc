#include "calc.h"

float calc_distance(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

float calc_distance_array(Map map)
{
    float total_distance = 0.0;
    for (int i = 0; i < map.size - 1; i++)
        total_distance += calc_distance(map.cities[i].x, map.cities[i].y,
                                        map.cities[i + 1].x, map.cities[i + 1].y);
    return total_distance;
}

Map generate_random_path(Map map, int size)
{
    Map shuffled_map = map;
    City temp;
    for (int i = 0; i < size; i++)
    {
        int random_index = rand() % size;
        temp = shuffled_map.cities[i];
        shuffled_map.cities[i] = shuffled_map.cities[random_index];
        shuffled_map.cities[random_index] = temp;
    }
    return shuffled_map;
}

Map swap_cities(Map map, int first_group, int second_group, int size)
{
    City temp;
    Map swapped_map = map;
    for (int i = 0; i < size; i++)
    {
        temp = swapped_map.cities[first_group + i];
        swapped_map.cities[first_group + i] = swapped_map.cities[second_group + i];
        swapped_map.cities[second_group + i] = temp;
    }
    return swapped_map;
}

Map mutate(Map map, int size)
{
    Map mutated_map = map;
    int length = rand() % size / 2;
    int first_group = rand() % (size - length);
    int second_group = first_group + length;
    return swap_cities(mutated_map, first_group, second_group, length);
}

int map_comparison(const void *a, const void *b)
{
    Map map_a = *(Map *)a;
    Map map_b = *(Map *)b;
    if (map_a.size != map_b.size)
        return -1;
    return calc_distance_array(map_a) < calc_distance_array(map_b);
}