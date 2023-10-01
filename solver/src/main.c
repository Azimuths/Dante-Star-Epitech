/*
** EPITECH PROJECT, 2022
** solver
** File description:
** main file
*/

#include "solver.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char **map = NULL;

    if (argc < 2)
        return 84;
    if (!(map = load_file(argv[1]))) {
        return 84;
    }
    return find_path(map);
}
