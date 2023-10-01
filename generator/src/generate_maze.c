/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** generate_maze
*/

#include "generator.h"

int initialise_maze(char *array, int width, int height)
{
    for (int a = 0; a < (height + 1) / 2; ++a)
        for (int b = 0; b < (width + 1) / 2; ++b)
            array[(2 * a) * (width + 1) + 2 * b] = '*';
    for (int i = 0; i < width; ++i)
        array[(height - 2 + (height % 2)) * (width + 1) + i] = '*';
    for (int i = 1; i < height; ++i)
        array[i * (width + 1) - 3 + (width % 2)] = '*';
    array[(width + 1) * height - 2] = '*';
    return 0;
}
