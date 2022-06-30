/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** display a number
*/

void my_putchar(char c);

int my_put_nbr(long long nb)
{
    int inc;

    inc = 1;
    while (nb / inc >= 10)
        inc = inc * 10;
    while (inc != 0) {
        my_putchar((nb / inc) + 48);
        nb = nb % inc;
        inc = inc / 10;
    }
    return (0);
}
