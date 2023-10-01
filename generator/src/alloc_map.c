/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** alloc_map
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *alloc_array(int width, int height)
{
    char *array = calloc(height * (width + 1), sizeof(char *));

    for (int i = 0; i < height * (width + 1) - 1; ++i) {
        array[i] = 'X';
    }
    for (int i = 1; i < height; ++i) {
        array[i * (width + 1) - 1] = '\n';
    }
    return array;
}

int show_array(char *array, int width, int height)
{
    write(1 , array, (width + 1) * height - 1);
    return 0;
}
