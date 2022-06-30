/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-said.yassin
** File description:
** display
*/
#include "my.h"
#include "sokoban.h"

void place_o(char **tab, char **tab2, int i, int j)
{
    if (tab2[i][j] == 'O' && tab[i][j] != 'X' && tab[i][j] != 'P') {
        mvprintw(i, j, "O");
    } else {
        printw("%c", tab[i][j]);
    }
}

void display_all(char **tab, char **tab2, int i, int j)
{
    if (tab2[i][j] != 'O') {
        printw("%c", tab[i][j]);
    } else {
        place_o(tab, tab2, i, j);
    }
}

void display_tab(char **tab, char **tab2)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab2[i][j] != '\0'; j++)
            display_all(tab, tab2, i, j);
        printw("\n");
    }
}
