/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** binary_tree
*/

#include <stdlib.h>
#include "generator.h"

static int update_char(int index, char *array, int width, int height)
{
    int rd = rand() % 2;

    if (index == (width + 1) * height - 1)
        return 0;
    if (rd == 1)
        array[index + 1] = '*';
    else
        array[index + (width + 1)] = '*';
    return 0;
}

int binary_tree(char *array, int width, int height)
{
    for (int x = 0; x < width - 2; x += 2) {
        for (int y = 0; y < height - 2; y += 2) {
            update_char(y * (width + 1) + x, array, width, height);
        }
    }
    if (array[(width + 1) * height - 3] +
            array[(width + 1) * (height - 1) - 2] != 'X' * 2)
        return 0;
    if (rand() % 2 == 0)
        array[(width + 1) * height - 3] = '*';
    else
        array[(width + 1) * (height - 1) - 2] = '*';
    return 0;
}
