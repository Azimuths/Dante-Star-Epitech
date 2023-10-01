/*
** EPITECH PROJECT, 2021
** ex
** File description:
** ex header
*/

#ifndef DANTE_H_
    #define DANTE_H_

    #define NE_CELL(x, y)
    #define N_CELL(x, y)
    #define NW_CELL(x, y)
    #define W_CELL(x, y)
    #define SW_CELL(x, y)
    #define S_CELL(x, y)
    #define SE_CELL(x, y)
    #define E_CELL(x, y)

    typedef enum status_e {
        UNDEFINED,
        OPENED,
        CLOSED
    } status_t;

    typedef struct vector_s {
        int x;
        int y;
    } vector_t;

    typedef struct cell_s {
        int fvalue;
        int gvalue;
        int hvalue;
        vector_t pos;
        status_t status;
        struct cell_s *parent;
    } cell_t;

    #define INT_MAX 2147483646

    char **load_file(char *filename);
    int *load_char_file(char *filename);
    cell_t **make_value_map(char ** const map);
    int find_path(char **map);
    int array_len(char **map);
    int all_closed(cell_t **cells, int width, int height);
    int find_path(char **map);
    vector_t find_minimum(cell_t **cells, int width, int height);
    int show_array(char **array, int width, int height);

#endif
