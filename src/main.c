#include "route.h"
#include "file.h"
#include "graphics.h"
#include "calc.h"
#include <time.h>

int main()
{
    // Initialize all the variables
    srand(time(NULL));
    FILE *file = open_file("data/cities.txt");
    if(file == NULL)
    {
        printf("Error: Could not open file\n");
        return -1;
    }
    Route cities = init_route();
    parse_file(file, &cities);
    RouteCollection list = init_route_collection();
    print_map_inline(cities);
    create_initial_RouteCollection(&list, &cities, CYCLE_SIZE);
    print_list_map(list);
    close_file(file);
    // Initialize the MLV window
    MLV_create_window("Cities", "Cities", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_change_frame_rate(60);
    MLV_Keyboard_button key;

    while(1)
    {

        genetic_loop(&list, MUTATION_SIZE, BEST_SIZE, RANDOM_SIZE);
        MLV_print_world(list);
        print_map_inline(list.paths[0]);
        MLV_delay_according_to_frame_rate();
    }
    
    return 0;
}