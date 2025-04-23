#include "city.h"
#include "file.h"
#include "graphics.h"
#include "calc.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *file = open_file("data/cities.txt");
    Route *cities = init_map();
    RouteCollection *list = init_map_list();
    parse_file(file, cities);
    add_map_to_list(list, *cities);
    Route random_path = generate_random_path(*cities, cities->size);
    add_map_to_list(list, random_path);
    print_list_map(*list);
    return 0;
}