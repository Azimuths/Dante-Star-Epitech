/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** generator
*/

#ifndef GENERATOR_H
    #define GENERATOR_H

    typedef struct vector_s {
        int x;
        int y;
    } vector_t;

    char *alloc_array(int width, int height);
    int show_array(char *array, int width, int height);
    int generator(char *x, char *y, int is_perfect);
    int initialise_maze(char *array, int width, int height);
    int binary_tree(char *array, int width, int height);

#endif
