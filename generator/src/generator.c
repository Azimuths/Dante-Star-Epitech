/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** generator
*/

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

int generator(char *x, char *y, int is_perfect)
{
    int width = atoi(x);
    int heigth = atoi(y);
    char *array = NULL;

    if (width <= 0 || heigth <= 0)
        return 84;
    array = alloc_array(width, heigth);
    initialise_maze(array, width, heigth);
    binary_tree(array, width, heigth);
    if (is_perfect == 1) {
        for (int i = 0; i < heigth; ++i)
            array[(width / 2) + i * (width + 1)] = '*';
        for (int j = 0; j < width; ++j)
            array[(heigth / 2) * (width + 1) + j] = '*';
    }
    return show_array(array, width, heigth);
}
