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

    printf("---ORIGINAL MAP---\n");
    print_map_inline(*cities);

    for (int i = 0; i < 10; i++)
        add_map_to_list(list, generate_random_path(*cities, cities->size));

    printf("\n---RANDOM MAPS---\n");
    print_list_map(*list);
    close_file(file);
}