/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** turn an str into an array
*/

#include <stdlib.h>
#include <stdio.h>

void my_putstr(char *);
void my_put_nbr(int);
char **suppr(char **);
char *pop_str(char const *, int);

int is_char(char c)
{
    if (c == '\n')
        return (1);
    else
        return (0);
}

char *if_char(int *i, char *str, int *last_char)
{
    int len = *i - *last_char;
    char *word;
    int incr = 0;

    word = malloc(sizeof(char) * (len + 1));
    for (; incr < len; incr++) {
        word[incr] = str[*last_char];
        *last_char = *last_char + 1;
    }
    word[incr] = '\0';
    *last_char = *last_char + 1;
    return (word);
}

int create_array(char *str)
{
    int taille_arr = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_char(str[i]) == 1)
            taille_arr = taille_arr + 1;
    return (taille_arr);
}

char **my_str_to_word_array(char *str)
{
    int last_char = 0;
    int where_in_arr = 0;
    char **tab;
    int test = create_array(str) + 1;
    int incr = 0;

    tab = malloc(sizeof(char *) * (test + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_char(str[i]) >= 1) {
            tab[where_in_arr] = if_char(&i, str, &last_char);
            where_in_arr++;
        }
        incr++;
    }
    tab[where_in_arr] = if_char(&incr, str, &last_char);
    where_in_arr++;
    tab[where_in_arr] = NULL;
    return (suppr(tab));
}
