/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-said.yassin
** File description:
** player_handeling
*/

#include "my.h"
#include "sokoban.h"

char **move_p(int p, char **map, int *i, int *j)
{
    struct move moving[] = MVT_P;

    for (int y = 0; y != 4; y++) {
        if (P_VAL == ' ' || map[moving[y].i][moving[y].j] == 'O')) {
            map[*i][*j] = ' ';
            map[moving[y].i][moving[y].j] = 'P';
            *i = moving[y].i;
            *j = moving[y].j;
            return map;
        }
        if (P_VAL == 'X' && (MAP_BEH == ' ' || MAP_BEH == 'O'))) {
            map[*i][*j] = ' ';
            map[moving[y].i][moving[y].j] = 'P';
            MAP_BEH = 'X';
            *i = moving[y].i;
            *j = moving[y].j;
            return map;
        }
    }
    return map;
}

void is_p(char c, struct pos_p **pos, int i, int j)
{
    if (c == 'P') {
        (*pos)->i = i;
        (*pos)->j = j;
    }
}

void found_p(char **map, struct pos_p **pos)
{
    int i = 0;
    int j = 0;

    for (; map[i] != NULL; i++) {
        for (; map[i][j] != '\0'; j++)
            is_p(map[i][j], pos, i, j);
        j = 0;
    }
}
