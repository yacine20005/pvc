#include "route.h"
#include "file.h"
#include "graphics.h"
#include "calc.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *file = open_file("data/cities.txt");
    Route *cities = init_route();
    RouteCollection *list = init_route_collection();
    parse_file(file, cities);
    add_route_to_collection(list, *cities);
    Route random_path = generate_random_path(*cities, cities->size);
    add_route_to_collection(list, random_path);
    print_list_map(*list);
    return 0;
}