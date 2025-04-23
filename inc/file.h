#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "city.h"

#define LINE_SIZE 256

/**
 * @brief Open a file in read mode
 *
 * @param filename The name of the file to open
 * @return FILE The file stream pointer
 */
FILE *open_file(char *);

/**
 * @brief Close a file
 *
 * @param file The file to close
 * @return FILE* The file stream pointer
 */
FILE *close_file(FILE *);

/**
 * @brief Get all the cities and their coordinates from a file
 *
 * @param file The file to read
 * @param route The route to fill with cities
 * @return int 1 if the file was read successfully, 0 otherwise
 */
int parse_file(FILE *file, Route *route);

#endif // FILE_H