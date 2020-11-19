/*
** EPITECH PROJECT, 2019
** list_args
** File description:
** list_ars
*/

#include "my.h"
#include "minishell.h"

int end_tab(char *str, command *arg, int i, int j)
{
    for (; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    if (str && !str[i])
        arg->args[j] = NULL;
    return (i);
}

command *list_args(char *str, command *arg, int i)
{
    int j = 0;
    int k = 0;

    for (; str && str[i];) {
        if (arg->args[j] == NULL)
            return (NULL);
        if (str[i] && str[i] != ' ' && str[i] != '\t') {
            arg->args[j][k] = str[i];
            k++;
            arg->args[j][k] = 0;
            i++;
        }
        else {
            j++;
            arg->args[j] = malloc(sizeof(char) * my_strlen(str));
            k = 0;
            i = end_tab(str, arg, i, j);
        }
    }
    arg->args[j + 1] = NULL;
    return (arg);
}
