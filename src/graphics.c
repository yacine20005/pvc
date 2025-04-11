#include "graphics.h"
#include "calc.h"

void print_map(Map map)
{
    for (int i = 0; i < map.size; i++)
    {
        printf("City: %s, Coordinates: (%d, %d)\n", map.cities[i].name, map.cities[i].x, map.cities[i].y);
    }
}

void print_map_inline(Map map)
{
    for (int i = 0; i < map.size; i++)
    {
        printf("%s | ", map.cities[i].name);
    }
    printf("Total distance: %.2f\n", calc_distance_array(map));
    printf("\n");
}

void print_list_map(MapList lst){
    for (int i = 0; i < lst.size; i++){
        printf("Path %d: \n", i);
        print_map_inline(lst.path[i]);
        printf("\n");
    }
}

void MLV_print_cities(Map map, int x_offset, int y_offset){
    for (int i = 0; i < map.size; i++)
    {
        MLV_draw_text(map.cities[i].x + x_offset, map.cities[i].y + y_offset - WINDOW_HEIGHT / 100, map.cities[i].name, MLV_COLOR_BLACK);
        MLV_draw_filled_circle(map.cities[i].x + x_offset, map.cities[i].y + y_offset, 5, MLV_COLOR_RED);
    }
}

void MLV_print_path(Map map, MLV_Color color, int x_offset, int y_offset){
    for (int i = 0; i < map.size - 1; i++)
        MLV_draw_line(map.cities[i].x + x_offset, map.cities[i].y + y_offset, map.cities[i + 1].x + x_offset, map.cities[i + 1].y + y_offset, color);
}

void MLV_print_list_map(MapList lst, int x_offset, int y_offset){
    for (int i = 0; i < lst.size; i++)
        MLV_print_path(lst.path[i], MLV_rgba(i * 255 / lst.size, 0, 0, 255), x_offset, y_offset);
}


void MLV_print_world(MapList lst){

    if(lst.size <= 0)
        return;
    int max_x = max_x_map(lst.path[0]);
    int max_y = max_y_map(lst.path[0]);
    int x_offset = (WINDOW_WIDTH - max_x) / 2;
    int y_offset = (WINDOW_HEIGHT - max_y) / 2;
    MLV_clear_window(MLV_COLOR_WHITE);
    MLV_print_cities(lst.path[0], x_offset, y_offset);
    MLV_print_list_map(lst, x_offset, y_offset);
    MLV_actualise_window();
}