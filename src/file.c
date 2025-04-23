#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *open_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    return file;
}

FILE *close_file(FILE *file)
{
    if (file != NULL)
        fclose(file);
    return NULL;
}

int parse_file(FILE *file, Route *route)
{
    if (file == NULL || route == NULL)
        return 0;

    char line[LINE_SIZE];
    char city_name[50];
    int x, y;

    while (fgets(line, LINE_SIZE, file) != NULL)
    {
        if (sscanf(line, "%s %d %d", city_name, &x, &y) == 3)
        {
            strcpy(route->cities[route->size].name, city_name);
            route->cities[route->size].x = x;
            route->cities[route->size].y = y;
            route->size++;
        }
    }

    return 1;
}