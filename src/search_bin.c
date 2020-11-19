/*
** EPITECH PROJECT, 2019
** search_bin
** File description:
** search_bin
*/

#include "minishell.h"

char **init_tab(char *path, char **tab)
{
    int nb = 0;

    for (int i = 0; path && path[i]; i++)
        if (path[i] == ':')
            nb++;
    if ((tab = malloc(sizeof(char *) * (nb + 1))) == NULL)
        return (NULL);
    if ((tab[0] = malloc(sizeof(char) * my_strlen(path))) == NULL)
        return (NULL);
    return (tab);
}

char **divide_str(char *path)
{
    int j = 0;
    int k = 0;
    char **tab = NULL;

    if ((tab = init_tab(path, tab)) == NULL)
        return (NULL);
    for (int i = 0; path && path[i]; i++) {
        if (tab[k] == NULL)
            return (NULL);
        if (path[i] == ':') {
            tab[k][j] = 0;
            k++;
            tab[k] = malloc(sizeof(char) * my_strlen(path));
            j = 0;
        }
        else {
            tab[k][j] = path[i];
            j++;
        }
    }
    return (tab);
}

char *search_bin(command *arg, char *str)
{
    char *path = NULL;
    char **tab = NULL;
    int fd = 0;
    char *result = NULL;

    path = catch_settings(arg, "PATH");
    if ((tab = divide_str(path)) == NULL)
        return (str);
    for (int i = 0; tab && tab[i]; i++) {
        result = my_strcat(my_strcat(tab[i], "/"), str);
        fd = open(result, O_RDONLY);
        if (fd >= 0) {
            close(fd);
            return (result);
        }
    }
    return (my_strcat("/bin/", str));
}
