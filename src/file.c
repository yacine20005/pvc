#include "file.h"
#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }
    return file;
}

FILE *close_file(FILE *file)
{
    if (file != NULL)
    {
        fclose(file);
    }
    return NULL;
}

int parse_file(FILE *file, Map *map)
{
    if (file == NULL || map == NULL)
    {
        return 0;
    }
    int index;
    char line[LINE_SIZE];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        index = map->size;
        if (sscanf(line, "%s %d %d", map->cities[index].name, &map->cities[index].x, &map->cities[index].y) == 3)
        {
            map->size++;
        }
    }
    return 1;
}