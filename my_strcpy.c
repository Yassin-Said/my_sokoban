/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy an str into an other one
*/

#include <stdlib.h>

int my_strlen(char *);

char *my_strcpy(char *dest, char *src)
{
    int len;
    int incr = 0;

    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    for (; incr != len; incr++)
        dest[incr] = src[incr];
    dest[incr] = '\0';
    return (dest);
}
