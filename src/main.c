#include "city.h"
#include "file.h"
#include "graphics.h"

int main()
{
    FILE *file = open_file("data/cities.txt");
    Map *cities = init_map();
    parse_file(file, cities);
    print_map(*cities);
    close_file(file);
}