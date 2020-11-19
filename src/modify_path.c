/*
** EPITECH PROJECT, 2019
** modify_path
** File description:
** modify_path
*/

#include "my.h"
#include "minishell.h"

char *void_begin(char *str)
{
    int j = 0;
    int i = 0;
    char *buff = malloc(sizeof(str) + 1);

    if (buff == NULL)
        return (NULL);
    for (i = 0; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    for (j = 0; str && str[i]; i++) {
        buff[j] = str[i];
        j++;
    }
    buff[j] = 0;
    return (buff);
}

int detect_sets(char **env, char *name)
{
    char *buff = NULL;
    int j = 0;

    for (int i = 0; env && env[i]; i++) {
        buff = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        for (j = 0; env[i] && env[i][j] && env[i][j] != '='; j++) {
            buff[j] = env[i][j];
        }
        buff[j] = 0;
        if (my_strcmp(buff, name) == 0) {
            free(buff);
            return (i);
        }
        free(buff);
    }
    return (-1);
}

void modify_path_others(command *arg, char *str, char *path)
{
    char *new_path = NULL;
    int s = detect_sets(arg->env, "PWD");

    if (str && my_strcmp(str, "-") == 0 && arg->prev != NULL) {
        chdir(arg->prev);
        my_setenv(arg, "PWD", arg->prev);
    }
    else if (s >= 0 && arg->env && arg->env[s] && str && my_strlen(str) > 0) {
        str = cut_str(str);
        new_path = malloc(sizeof(char) *
        (my_strlen(arg->env[s]) + my_strlen(str)));
        new_path = my_strcat(path, str);
        chdir(new_path);
        my_setenv(arg, "PWD", new_path);
    }
}

void modify_path(command *arg, char *str)
{
    char *path = catch_settings(arg, "PWD");
    char *home = catch_settings(arg, "HOME");

    str = void_begin(str);
    if (!(str) || my_strlen(str) == 0 || my_strcmp(str, "~") == 0) {
        chdir(home);
        my_setenv(arg, "PWD", home);
    }
    else
        modify_path_others(arg, str, path);
    arg->prev = my_strdup(path);
}
