/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** concatenate 2 string in range of a number
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_strncat(char *dest, char *src, int nb, int *len)
{
    int i = 0;

    for (; nb > 0; nb--) {
        my_put_nbr(*len);
        my_putchar(' ');
        dest[*len] = src[i];
        *len = *len + 1;
        i++;
    }
    return (dest);
}
