/*
** EPITECH PROJECT, 2022
** B-CPE-200-BDX-2-1-dante-edouard.chhang
** File description:
** load_file
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "solver.h"

int check_file(char *file)
{
    for (int i = 0; file[i] != '\0'; i++) {
        switch (file[i]) {
            default:
                return 84;
            case '\n':
            case '\0':
            case '*':
            case 'X':;
        }
    }
    return 0;
}

int count_line(char const *str)
{
    int count = 0;

    if (!str) {
        return 84;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            ++count;
        }
    }
    return count + 1;
}

char **load_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat st;
    char *buf = NULL;
    char **dest = NULL;

    if (fd < 0)
        return NULL;
    stat(filename, &st);
    buf = calloc(st.st_size + 1, sizeof(char));
    if ((read(fd, buf, st.st_size)) < st.st_size)
        return NULL;
    if (check_file(buf)) {
        fprintf(stderr, "Invalid character found in maze\n");
        return NULL;
    }
    dest = calloc(count_line(buf) + 1, sizeof(char *));
    dest[0] = strtok(buf, "\n");
    for (int i = 1; (dest[i] = strtok(NULL, "\n")); i++);
    return dest;
}

int show_array(char **array, int width, int height)
{
    for (int i = 0; i < width; ++i) {
        write(1, array[i], height);
        if (i < width - 1)
            write(1, "\n", 1);
    }
    return 0;
}
