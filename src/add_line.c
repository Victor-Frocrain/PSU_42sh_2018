/*
** EPITECH PROJECT, 2019
** add_line
** File description:
** add_line
*/

#include "my.h"
#include "minishell.h"

void add_line(command *arg, char *name, char *str)
{
    int i = 0;
    char **env = NULL;

    for (i = 0; arg->env && arg->env[i]; i++);
    env = malloc(sizeof(char *) * (i + 1));
    for (i = 0; arg->env && arg->env[i]; i++)
        env[i] = my_strdup(arg->env[i]);
    env[i] = my_strdup(my_strcat(name, my_strcat("=", str)));
    env[i + 1] = NULL;
    arg->env = env;
}
