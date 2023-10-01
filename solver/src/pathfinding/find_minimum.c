/*
** EPITECH PROJECT, 2022
** dante_star
** File description:
** find_minimum
*/

#include "solver.h"

vector_t find_minimum(cell_t **cells, int width, int height)
{
    int x = 0;
    int y = 0;
    vector_t min_coords = {-1, -1};
    int min_val = -1;

    for (int i = 0; i < width * height; ++i) {
        x = i / height;
        y = i % height;
        if (cells[x][y].status != OPENED)
            continue;
        if (cells[x][y].fvalue < min_val || min_val == -1) {
            min_val = cells[x][y].fvalue;
            min_coords = ((vector_t){.x = x, .y = y});
        }
    }
    if (min_coords.y == -1)
        return ((vector_t){-1, -1});
    return min_coords;
}
