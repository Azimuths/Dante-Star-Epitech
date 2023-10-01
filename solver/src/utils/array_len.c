/*
** EPITECH PROJECT, 2022
** dante_star
** File description:
** array_len
*/

#include <stddef.h>
#include "solver.h"

int array_len(char **map)
{
    int i = 0;

    if (map == NULL)
        return -1;
    for (; map[i] != NULL; ++i);
    return i;
}
