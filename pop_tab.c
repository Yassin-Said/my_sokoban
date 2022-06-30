/*
** EPITECH PROJECT, 2021
** pop_tab
** File description:
** erase an element and he's emplacement on a array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int tab_len(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

char **pop_tab(char **tab, int i)
{
    int incr = 0;
    int incr2 = 0;
    char **new_tab = malloc(sizeof(char *) * (tab_len(tab) + 1));

    while (incr != tab_len(tab)) {
        if (incr != i) {
            new_tab[incr2] = my_strcpy(new_tab[incr2], tab[incr]);
            incr2++;
        }
        incr++;
    }
    free_tab(tab);
    new_tab[incr] = NULL;
    return (new_tab);
}
