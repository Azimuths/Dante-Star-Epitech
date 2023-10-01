/*
** EPITECH PROJECT, 2022
** dante_star
** File description:
** all_closed
*/

#include "solver.h"

int all_closed(cell_t **cells, int width, int height __attribute__((unused)))
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < width * height; ++i) {
        x = i / width;
        y = i % width;
        if (cells[x][y].status == OPENED)
            return 0;
    }
    return 1;
}
