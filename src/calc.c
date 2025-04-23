#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int max_x_map(Map map)
{
    int max_x = map.cities[0].x;
    for (int i = 1; i < map.size; i++)
        if (map.cities[i].x > max_x)
            max_x = map.cities[i].x;
    return max_x;
}

int max_y_map(Map map)
{
    int max_y = map.cities[0].y;
    for (int i = 1; i < map.size; i++)
        if (map.cities[i].y > max_y)
            max_y = map.cities[i].y;
    return max_y;
}

int evolve_list_map(MapList *list)
{
    if (list == NULL || list->size == 0)
        return -1;

    // Trier V dans l'ordre croissant selon la longueur des visites
    qsort(list->path, list->size, sizeof(Map), map_comparison);

    // Créer une nouvelle liste V' pour stocker les nouvelles visites
    MapList new_list;
    new_list.size = list->size;

    // Définir les paramètres alpha, beta et gamma
    int alpha = MUTATION_SIZE;
    int beta = MUTATION_SIZE;
    int gamma = list->size - (alpha + beta);

    // 1. Appliquer des mutations aux alpha meilleurs chemins
    for (int i = 0; i < alpha; i++)
    {
        // Mutation des meilleurs chemins (v1, v2, ..., v_alpha)
        new_list.path[i] = mutate(list->path[i % beta], list->path[0].size);
    }

    // 2. Conserver beta meilleurs chemins sans modification
    for (int i = 0; i < beta; i++)
    {
        // Garder les meilleurs chemins (v1, v2, ..., v_beta)
        new_list.path[alpha + i] = list->path[i];
    }

    // 3. Générer gamma chemins aléatoires
    for (int i = 0; i < gamma; i++)
    {
        // Générer de nouvelles visites aléatoires
        new_list.path[alpha + beta + i] = generate_random_path(list->path[0], list->path[0].size);
    }

    // Copier la nouvelle liste dans l'ancienne
    for (int i = 0; i < list->size; i++)
    {
        list->path[i] = new_list.path[i];
    }

    // Trier à nouveau la liste selon la longueur des chemins
    qsort(list->path, list->size, sizeof(Map), map_comparison);

    return 0;
}

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
    int length = (rand() % size) / 2;
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
    float distance_a = calc_distance_array(map_a);
    float distance_b = calc_distance_array(map_b);
    if (distance_a < distance_b)
        return -1;
    else if (distance_a > distance_b)
        return 1;
    else
        return 0;
}