/*
** EPITECH PROJECT, 2022
** dante star - solver
** File description:
** pathfinding algorithme
*/

#include "solver.h"
#include <stdio.h>
#include <string.h>

int print_solution(char **map, cell_t **cells, vector_t size)
{
    cell_t *cell = NULL;

    cell = &cells[size.x - 1][size.y - 1];
    while (cell != *cells) {
        map[cell->pos.x][cell->pos.y] = 'o';
        cell = cell->parent;
    }
    map[0][0] = 'o';
    show_array(map, size.x, size.y);
    return 0;
}

int update_cell(cell_t **cell, vector_t from, vector_t child, vector_t size)
{
    if (cell[child.x][child.y].status != OPENED)
        cell[child.x][child.y].status = OPENED;
    if (cell[child.x][child.y].hvalue == INT_MAX)
        cell[child.x][child.y].hvalue = (size.x + size.y - child.x - child.y)
        * 11;
    if (cell[from.x][from.y].gvalue + 10 < cell[child.x][child.y].gvalue) {
        cell[child.x][child.y].gvalue = cell[from.x][from.y].gvalue + 10;
        cell[child.x][child.y].parent = &cell[from.x][from.y];
    }
    cell[child.x][child.y].fvalue = cell[child.x][child.y].hvalue +
    cell[child.x][child.y].gvalue;
    return 0;
}

int explore(cell_t **cell, vector_t pos, vector_t size)
{
    cell[pos.x][pos.y].status = CLOSED;
    if (cell[pos.x + 1] != NULL && cell[pos.x + 1][pos.y].status != CLOSED)
        update_cell(cell, pos, ((vector_t){.x = pos.x + 1, .y = pos.y}), size);
    if (pos.x > 0 && cell[pos.x - 1][pos.y].status != CLOSED)
        update_cell(cell, pos, ((vector_t){.x = pos.x - 1, .y = pos.y}), size);
    if (pos.y < size.y && cell[pos.x][pos.y + 1].status != CLOSED)
        update_cell(cell, pos, ((vector_t){.x = pos.x, .y = pos.y + 1}), size);
    if (pos.y > 0 && cell[pos.x][pos.y - 1].status != CLOSED)
        update_cell(cell, pos, ((vector_t){.x = pos.x, .y = pos.y - 1}), size);
    return 0;
}

#include "unistd.h"

int find_path(char **map)
{
    cell_t **cells = make_value_map(map);
    vector_t size = {0};
    vector_t vector = {0};

    if (map[0][0] == 'X')
        return printf("no solution found\n") * 0;
    size.x = array_len(map);
    size.y = (int)strlen(*map);
    cells[0][0].status = OPENED;
    cells[0][0].gvalue = 0;
    while (all_closed(cells, size.y, size.x) == 0) {
        vector = find_minimum(cells, size.x, size.y);
        if ((vector.x == size.x - 1) && (vector.y == size.y - 1))
            return print_solution(map, cells, size);
        explore(cells, vector, size);
    }
    printf("no solution found");
    return 0;
}
