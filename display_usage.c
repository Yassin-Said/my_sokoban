/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** display_usage
*/

#include "sokoban.h"

void display_usage(void)
{
    my_putstr("USAGE\n      ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n      map file representing the warehouse map,");
    my_putstr("containing '#' for walls,\n");
    my_putstr("          'P' for the player, 'X' for boxes and 'O' for");
    my_putstr("storage locations.\n");
}
