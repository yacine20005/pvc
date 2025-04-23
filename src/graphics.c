#include "graphics.h"
#include "calc.h"

void print_map(Route map)
{
    for (int i = 0; i < map.size; i++)
    {
        printf("City: %s, Coordinates: (%d, %d)\n", map.cities[i].name, map.cities[i].x, map.cities[i].y);
    }
}

void print_map_inline(Route map)
{
    for (int i = 0; i < map.size; i++)
    {
        printf("%s | ", map.cities[i].name);
    }
    printf("Total distance: %.2f\n", calc_distance_array(map));
    printf("\n");
}

void print_list_map(RouteCollection lst)
{
    for (int i = 0; i < lst.size; i++)
    {
        printf("Path %d: \n", i);
        print_map_inline(lst.paths[i]);
        printf("\n");
    }
}

void get_min_max_coordinate(Route route, int *min_max)
{
    min_max[0] = route.cities[0].x;
    min_max[1] = route.cities[0].y;
    min_max[2] = route.cities[0].x;
    min_max[3] = route.cities[0].y;

    for (int i = 1; i < route.size; i++)
    {
        if (route.cities[i].x < min_max[0])
            min_max[0] = route.cities[i].x;

        if (route.cities[i].y < min_max[1])
            min_max[1] = route.cities[i].y;

        if (route.cities[i].x > min_max[2])
            min_max[2] = route.cities[i].x;

        if (route.cities[i].y > min_max[3])
            min_max[3] = route.cities[i].y;
    }
}


int calculate_scale_x(int min_x, int max_x, int width)
{
    if (max_x - min_x == 0)
        return 1;
    return width / (max_x - min_x);
}

int calculate_scale_y(int min_y, int max_y, int height)
{
    if (max_y - min_y == 0)
        return 1;
    return height / (max_y - min_y);
}

void MLV_print_cities(Route map, int scale_x, int scale_y)
{
    for (int i = 0; i < map.size; i++)
    {
        MLV_draw_text(map.cities[i].x * scale_x, map.cities[i].y * scale_y - WINDOW_HEIGHT / 100, map.cities[i].name, MLV_COLOR_BLACK);
        MLV_draw_filled_circle(map.cities[i].x * scale_x, map.cities[i].y * scale_y, 5, MLV_COLOR_RED);
    }
}

void MLV_print_path(Route map, MLV_Color color, int scale_x, int scale_y)
{
    for (int i = 0; i < map.size - 1; i++)
        MLV_draw_line(map.cities[i].x * scale_x, map.cities[i].y * scale_y,
                      map.cities[i + 1].x * scale_x, map.cities[i + 1].y * scale_y, color);
}

void MLV_print_list_map(RouteCollection lst, int scale_x, int scale_y)
{
    for (int i = 0; i < lst.size; i++)
        MLV_print_path(lst.paths[i], MLV_rgba(i * 255 / lst.size, 0, 0, 255), scale_x, scale_y);
}
void MLV_print_world(RouteCollection lst)
{
    if (lst.size <= 0)
        return;

    int min_max[4];
    get_min_max_coordinate(lst.paths[0], min_max);
    int min_x = min_max[0];
    int min_y = min_max[1];
    int max_x = min_max[2];
    int max_y = min_max[3];

    // int x_offset = (WINDOW_WIDTH - (max_x - min_x)) / 2;
    // int y_offset = (WINDOW_HEIGHT - (max_y - min_y)) / 2;
    int x_offset = 0;
    int y_offset = 0;

    int scale_x = calculate_scale_x(min_x, max_x, WINDOW_WIDTH);
    int scale_y = calculate_scale_y(min_y, max_y, WINDOW_HEIGHT);

    MLV_clear_window(MLV_COLOR_WHITE);
    MLV_print_cities(lst.paths[0], scale_x, scale_y);
    MLV_print_path(lst.paths[0], MLV_COLOR_BLUE, scale_x, scale_y);
    MLV_actualise_window();
}