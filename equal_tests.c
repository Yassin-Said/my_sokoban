/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-said.yassin
** File description:
** equal_tests
*/
#include "my.h"
#include "sokoban.h"

int equal_box(char **tab, int i, int j)
{
    if (tab[i][j] && tab[i][j] == 'X')
        return (1);
    return (0);
}

int equal_hashtag(char **tab, int i, int j)
{
    if (tab[i][j] && tab[i][j] == '#')
        return (1);
    return (0);
}
