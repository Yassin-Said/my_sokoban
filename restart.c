/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** restart
*/

#include "sokoban.h"

char **restart(struct pos_p *pos, char **tab, char **tab_o, char *map)
{
    (void)map;
    char **test = NULL;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
    test = tab_cpy(test, tab_o);
    found_p(test, &pos);
    return (test);
}
