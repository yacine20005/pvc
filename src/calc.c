#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int max_x_map(Route route)
{
    int max_x = route.cities[0].x;
    for (int i = 1; i < route.size; i++)
        if (route.cities[i].x > max_x)
            max_x = route.cities[i].x;
    return max_x;
}

int max_y_map(Route route)
{
    int max_y = route.cities[0].y;
    for (int i = 1; i < route.size; i++)
        if (route.cities[i].y > max_y)
            max_y = route.cities[i].y;
    return max_y;
}

int genetic_loop(RouteCollection *collection, int nb_mutation, int nb_best, int nb_random)
{
    if (collection == NULL || collection->size == 0)
        return -1;

    // Créer une nouvelle collection pour stocker les nouvelles visites
    RouteCollection new_collection;
    new_collection.size = collection->size;

    // Appliquer des mutations aux nb_mutation meilleurs chemins
    for (int i = 0; i < nb_mutation; i++)
    {
        new_collection.paths[i] = mutate(collection->paths[i], collection->paths[i].size);
    }

    // Conserver nb_best meilleurs chemins sans modification
    for (int i = 0; i < nb_best; i++)
    {
        // Garder les meilleurs chemins (v1, v2, ..., v_beta)
        new_collection.paths[nb_mutation + i] = collection->paths[i];
    }

    // Générer nb_random chemins aléatoires
    for (int i = 0; i < nb_random; i++)
    {
        // Générer de nouvelles visites aléatoires
        new_collection.paths[nb_mutation + nb_best + i] = generate_random_path(collection->paths[0], collection->paths[0].size);
    }

    // Copier la nouvelle collection dans l'ancienne
    for (int i = 0; i < collection->size; i++)
    {
        collection->paths[i] = new_collection.paths[i];
    }

    // Trier à nouveau la collection selon la longueur des chemins
    qsort(collection->paths, collection->size, sizeof(Route), map_comparison);

    return 0;
}

float calc_distance(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

float calc_distance_array(Route route)
{
    float total_distance = 0.0;
    for (int i = 0; i < route.size - 1; i++)
        total_distance += calc_distance(route.cities[i].x, route.cities[i].y,
                                        route.cities[i + 1].x, route.cities[i + 1].y);
    return total_distance;
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

Route swap_cities(Route route, int first_group, int second_group, int size)
{
    City temp;
    Route swapped_route = route;
    for (int i = 0; i < size; i++)
    {
        temp = swapped_route.cities[first_group + i];
        swapped_route.cities[first_group + i] = swapped_route.cities[second_group + i];
        swapped_route.cities[second_group + i] = temp;
    }
    return swapped_route;
}

Route mutate(Route route, int size)
{
    Route mutated_route = route;
    int length = (rand() % size) / 2;
    int first_group = rand() % (size - length);
    int second_group = first_group + length;
    return swap_cities(mutated_route, first_group, second_group, length);
}

int map_comparison(const void *a, const void *b)
{
    Route route_a = *(Route *)a;
    Route route_b = *(Route *)b;
    if (route_a.size != route_b.size)
        return -1;
    float distance_a = calc_distance_array(route_a);
    float distance_b = calc_distance_array(route_b);
    if (distance_a < distance_b)
        return -1;
    else if (distance_a > distance_b)
        return 1;
    else
        return 0;
}