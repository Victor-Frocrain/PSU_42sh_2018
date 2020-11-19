/*
** EPITECH PROJECT, 2019
** manage_env
** File description:
** manage_env
*/

#include "my.h"
#include "minishell.h"

char *fill_settings(char *ae, char *setting, int i)
{
    int j = 0;
    char *sets = malloc(sizeof(char) * (my_strlen(ae) + 1));

    for (j = 0; ae && ae[i]; i++) {
        sets[j] = ae[i];
        j++;
    }
    sets[j] = 0;
    return (sets);
}

char *catch_settings(command *arg, char *name)
{
    int i = 0;
    int j = 0;
    bool found = false;
    char *setting = NULL;

    for (i = 0; name && name[i] && (name[i] == ' ' || name[i] == '\t'); i++);
    for (j = 0; arg->env && arg->env[j] && !found && name && name[i]; j++)
        found = detect_name(arg->env[j], name + i);
    if (found) {
        j--;
        for (i = 0; arg->env && arg->env[j] && arg->env[j][i] != '='; i++);
        setting = malloc(sizeof(char) * (my_strlen(arg->env[j])));
        if (setting == NULL)
            return (NULL);
        i++;
        setting = fill_settings(arg->env[j], setting, i);
    }
    return (setting);
}
