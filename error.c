/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** error_cases
*/
#include "my.h"
#include "sokoban.h"

void compare(char c, int *nb_O, int *nb_X, int *nb_P)
{
    if (c == 'O') {
        *nb_O = *nb_O + 1;
        return;
    }
    if (c == 'X') {
        *nb_X = *nb_X + 1;
        return;
    }
    if (c == 'P') {
        *nb_P = *nb_P + 1;
        return;
    }
}

int loop_blocked_box(char **tab, int *index_i, int *index_j)
{
    int res = 0;
    int index = 0;

    for (; index != 4; index++) {
        res += equal_hashtag(tab, index_i[index], index_j[index]);
        res += equal_box(tab, index_i[index], index_j[index]);
        res += equal_hashtag(tab, index_i[index + 1], index_j[index + 1]);
        res += equal_box(tab, index_i[index + 1], index_j[index + 1]);
        if (res == 2)
            return (1);
        res = 0;
    }
    return (0);
}

int blocked_box(char c, char **tab, int i, int j)
{
    int index_i[] = {i, i + 1, i, i - 1, i};
    int index_j[] = {j + 1, j, j - 1, j, j + 1};

    if (c == 'X') {
        if (loop_blocked_box(tab, index_i, index_j) == 1)
            return (1);
    }
    return (0);
}

int parse_blocked_box(char **tab)
{
    int res = 0;
    int nb_box = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            nb_box += equal_box(tab, i, j);
            res += blocked_box(tab[i][j], tab, i, j);
        }
    }
    if (res == nb_box) {
        refresh();
        return (84);
    }
    return (0);
}

int nb_not_matching(char **map)
{
    int nb_O = 0;
    int nb_X = 0;
    int nb_P = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            compare(map[i][j], &nb_O, &nb_X, &nb_P);
    }
    if (nb_O != nb_X || nb_P != 1)
        return (84);
    return (1);
}
