#include "city.h"
#include "file.h"
#include "graphics.h"
#include "calc.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *file = open_file("data/cities.txt");
    Map *cities = init_map();
    MapList *list = init_map_list();
    parse_file(file, cities);
    MLV_create_window("Pathfinding Visualizer", "Pathfinding Visualizer", WINDOW_WIDTH, WINDOW_HEIGHT);

    for (int i = 0; i < 10; i++)
        add_map_to_list(list, generate_random_path(*cities, cities->size));
    qsort(list->path, list->size, sizeof(Map), map_comparison);
    MLV_print_world(*list);
    MLV_wait_seconds(5);
    MLV_free_window();
    close_file(file);
}