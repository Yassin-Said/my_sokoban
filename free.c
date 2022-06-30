/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-free-said.yassin
** File description:
** free.c
*/
#include "my.h"
#include "sokoban.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_all(struct pos_p *pos, char **tab, char **tab_o, int test)
{
    (void)test;
    (void)pos;
    if (tab != NULL)
        free_tab(tab);
    if (tab_o)
        free_tab(tab_o);
}
