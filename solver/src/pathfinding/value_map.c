/*
** EPITECH PROJECT, 2022
** dante star - solver
** File description:
** Value map making and managing
*/

#include "solver.h"
#include <stdlib.h>
#include <string.h>

cell_t make_free_cell(int x, int y)
{
    cell_t cell = {0};

    cell.fvalue = INT_MAX;
    cell.gvalue = INT_MAX;
    cell.hvalue = INT_MAX;
    cell.parent = NULL;
    cell.status = UNDEFINED;
    cell.pos = ((vector_t){.x = x, .y = y});
    return cell;
}

cell_t make_wall_cell()
{
    cell_t cell = {0};

    cell.fvalue = INT_MAX;
    cell.gvalue = INT_MAX;
    cell.hvalue = INT_MAX;
    cell.parent = NULL;
    cell.status = CLOSED;
    return cell;
}

cell_t **make_value_map(char ** const map)
{
    int x = 0;
    int y = 0;
    int width = strlen(*map);
    int height = array_len(map);
    cell_t **cells = malloc(sizeof(cell_t *) * (height + 1));

    for (int a = 0; a < height; ++a)
        cells[a] = malloc(sizeof(cell_t) * width);
    for (int i = 0; i < width * height; ++i) {
        x = i / width;
        y = i % width;
        if (map[x][y] == '*')
            cells[x][y] = make_free_cell(x, y);
        else
            cells[x][y] = make_wall_cell();
    }
    return cells;
}
