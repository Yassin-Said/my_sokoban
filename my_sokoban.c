/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-said.yassin
** File description:
** my_sokoban.c
*/
#include "my.h"
#include "sokoban.h"

int game_loop(char ***tab, char **tab_o, struct pos_p *pos, char *map)
{
    int res = 0;

    clear();
    display_tab(*tab, tab_o);
    if (won(*tab, tab_o))
        return (1);
    if (parse_blocked_box(*tab) == 84)
        return (2);
    if ((res = getch()) == ' ')
        *tab = restart(pos, *tab, tab_o, map);
    *tab = move_p(res, *tab, &pos->i, &pos->j);
    refresh();
    return (0);
}

int not_good_char2(char c)
{
    if (c == ' ' || c == '#' || c == 'X' || c == 'P') {
        return (0);
    } else if (c == 'O') {
        return (0);
    }
    return (1);
}

void not_good_char(char **tab)
{
    int test = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            test += not_good_char2(tab[i][j]);
    }
    if (test > 0) {
        endwin();
        exit(84);
    }
}

int main_loop(char **tab, char **tab_o, struct pos_p *pos, char *map)
{
    int ret = 0;
    if ((ret = nb_not_matching(tab)) == 84){
        free_all(pos, tab, tab_o, 0);
        free(pos);
        return (ret);
    }
    while (1) {
        if ((ret = game_loop(&tab, tab_o, pos, map)) != 0) {
            free_all(pos, tab, tab_o, 0);
            free(pos);
            endwin();
            return (ret - 1);
        }
    }
}

int main(int ac, char **av)
{
    struct pos_p *pos = malloc(sizeof(struct pos_p));
    char **tab = NULL;
    char **tab_o = NULL;

    if (ac > 3 || !av[1])
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_usage();
        return (0);
    }
    tab = fill_map(av[1]);
    if (!tab)
        return (84);
    tab = without_backline(tab);
    tab_o = tab_cpy(tab_o, tab);
    initscr();
    keypad(stdscr, TRUE);
    found_p(tab, &pos);
    not_good_char(tab);
    return (main_loop(tab, tab_o, pos, av[1]));
}
