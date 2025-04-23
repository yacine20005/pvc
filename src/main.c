#include "route.h"
#include "file.h"
#include "graphics.h"
#include "calc.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *file = open_file("data/cities.txt");
    Route cities;
    parse_file(file, &cities);
    RouteCollection list;
    create_initial_RouteCollection(&list, &cities, cities.size);

    print_list_map(*list);
    return 0;
}