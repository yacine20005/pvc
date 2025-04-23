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

void MLV_print_cities(Route map, int x_offset, int y_offset)
{
    for (int i = 0; i < map.size; i++)
    {
        MLV_draw_text(map.cities[i].x + x_offset, map.cities[i].y + y_offset - WINDOW_HEIGHT / 100, map.cities[i].name, MLV_COLOR_BLACK);
        MLV_draw_filled_circle(map.cities[i].x + x_offset, map.cities[i].y + y_offset, 5, MLV_COLOR_RED);
    }
}

void MLV_print_path(Route map, MLV_Color color, int x_offset, int y_offset)
{
    for (int i = 0; i < map.size - 1; i++)
        MLV_draw_line(map.cities[i].x + x_offset, map.cities[i].y + y_offset, map.cities[i + 1].x + x_offset, map.cities[i + 1].y + y_offset, color);
}

void MLV_print_list_map(RouteCollection lst, int x_offset, int y_offset)
{
    for (int i = 0; i < lst.size; i++)
        MLV_print_path(lst.paths[i], MLV_rgba(i * 255 / lst.size, 0, 0, 255), x_offset, y_offset);
}

void MLV_print_world(RouteCollection lst)
{
    if (lst.size <= 0)
        return;
    int max_x = max_x_map(lst.paths[0]);
    int max_y = max_y_map(lst.paths[0]);
    int min_x = min_x_map(lst.paths[0]);
    int min_y = min_y_map(lst.paths[0]);
    if (max_x > WINDOW_WIDTH)
        max_x = WINDOW_WIDTH;
    if (max_y > WINDOW_HEIGHT)
        max_y = WINDOW_HEIGHT;
    if (min_x < 0)
        min_x = 0;
    if (min_y < 0)
        min_y = 0;
    int x_offset = (WINDOW_WIDTH - (max_x - min_x)) / 2;
    int y_offset = (WINDOW_HEIGHT - (max_y - min_y)) / 2;
    int scale_x = (WINDOW_WIDTH - 2 * x_offset) / (max_x - min_x);
    int scale_y = (WINDOW_HEIGHT - 2 * y_offset) / (max_y - min_y);
    int scale = scale_x < scale_y ? scale_x : scale_y;
    x_offset += min_x * scale;
    y_offset += min_y * scale;

    MLV_clear_window(MLV_COLOR_WHITE);
    MLV_print_cities(lst.paths[0], x_offset, y_offset);
    MLV_print_path(lst.paths[0], MLV_COLOR_BLUE, x_offset, y_offset);
    MLV_actualise_window();
}