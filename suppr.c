/*
** EPITECH PROJECT, 2021
** suppr
** File description:
** suppress the strange space of my_str_to_word_array
*/
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char **suppr(char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        if (tab[i][0] == '\0') {
            tab = pop_tab(tab, i);
            i = 0;
        } else {
            i++;
        }
    }
    return (tab);
}
