/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** prototype for sokoban
*/
#include "my.h"
#include <sys/types.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#ifndef SOKOBAN_H
    #define SOKOBAN_H
    #define MVT_P {{KEY_DOWN, *i + 1, *j, *i + 2, *j},\
    {KEY_RIGHT, *i, *j + 1, *i, *j + 2}, {KEY_UP, *i - 1, *j, *i - 2, *j},\
    {KEY_LEFT, *i, *j - 1, *i, *j - 2}};
    #define P_VAL p == moving[y].move && (map[moving[y].i][moving[y].j]
    #define MAP_BEH map[moving[y].behind_i][moving[y].behind_j]

struct pos_p {
    int i;
    int j;
};

struct move {
    int move;
    int i;
    int j;
    int behind_i;
    int behind_j;
};

char **without_backline(char **tab);
char **move_p(int p, char **map, int *i, int *j);
void found_p(char **map, struct pos_p **pos);
int won(char **tab, char **tab2);
void display_tab(char **tab, char **tab2);
int equal_box(char **tab, int i, int j);
int equal_hashtag(char **tab, int i, int j);
void free_all(struct pos_p *pos, char **tab, char **tab_o, int test);
void free_tab(char **tab);
int nb_not_matching(char **map);
int parse_blocked_box(char **tab);
FILE *fs_open(char const *filepath);
char **fill_map(char *filepath);
char **tab_cpy(char **dest, char **tab);
int my_tablen(char **tab);
void display_usage(void);
char **restart(struct pos_p *pos, char **tab, char **tab_o, char *map);

#endif /* !SOKOBAN_H */
