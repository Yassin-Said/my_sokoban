/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** map_hendeling
*/

#include <sokoban.h>

char **without_backline(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][my_strlen(tab[i]) - 1] == '\n')
            tab[i][my_strlen(tab[i]) - 1] = '\0';
    }
    return (tab);
}

FILE *fs_open(char const *filepath)
{
    FILE *fd = 0;

    fd = fopen(filepath, "r");
    if (fd == NULL)
        return (NULL);
    return (fd);
}

char **fill_map(char *filepath)
{
    FILE *path = fs_open(filepath);
    char **tab = malloc(sizeof(char *) * 100);
    size_t size = 0;
    char *buffer = NULL;
    int i = 0;

    if (!path)
        return (NULL);
    while (getline(&buffer, &size, path) != -1) {
        tab[i] = my_strcpy(tab[i], buffer);
        i++;
    }
    tab[i] = NULL;
    fclose(path);
    free(buffer);
    return (tab);
}

char **tab_cpy(char **dest, char **tab)
{
    int i = 0;
    dest = malloc(sizeof(char *) * (my_tablen(tab) + 1));

    for (; tab[i] != NULL; i++)
        dest[i] = my_strcpy(dest[i], tab[i]);
    dest[i] = NULL;
    return (dest);
}

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}
