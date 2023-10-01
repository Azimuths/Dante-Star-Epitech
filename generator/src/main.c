/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <time.h>
#include <stdlib.h>
#include "generator.h"

int main(int argc, char **argv)
{
    if (argc <= 2 || argc >= 5)
        return 84;
    srand(time(NULL));
    return generator(argv[1], argv[2], !(argc - 3));
}
