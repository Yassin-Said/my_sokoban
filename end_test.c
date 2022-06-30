/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-said.yassin
** File description:
** end_test
*/
#include "my.h"
#include "sokoban.h"

int is_not_over(char tab, char tab2)
{
    if (tab2 == 'O') {
        if ( tab == 'X')
            return (0);
        return (1);
    }
    return (0);
}

int won(char **tab, char **tab2)
{
    int test = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab2[i][j] != '\0'; j++)
            test += is_not_over(tab[i][j], tab2[i][j]);
    }
    if (test == 0) {
        refresh();
        return (1);
    }
    return (0);
}
