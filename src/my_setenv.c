/*
** EPITECH PROJECT, 2019
** my_setenv
** File description:
** my_setenv
*/

#include "my.h"
#include "minishell.h"

char **detect_setenv_args(command *arg2, int i, char *str)
{
    int k = 0;
    int j = 0;
    char **buff = malloc(sizeof(char *) * 4);

    for (j = 0; str && str[i] && j < 3; j++) {
        buff[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        for (; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
        for (k = 0; str && str[i] && str[i] != ' ' && str[i] != '\t'; i++) {
            buff[j][k] = str[i];
            k++;
        }
        buff[j][k] = 0;
    }
    if (j < 1) {
        disp_env(arg2);
        return (NULL);
    }
    if (buff && buff[0] && detect_characters(buff[0]) == false)
        return (NULL);
    buff[j] = NULL;
    return (buff);
}

bool detect_name(char *ae, char *str)
{
    for (int j = 0; ae && ae[j] && ae[j] != '='; j++) {
        if (str && str[j] && str[j] != ae[j])
            break;
        else if (str && ae[j + 1] && ae[j + 1] == '=' &&
            str[j] && str[j] == ae[j])
            return (true);
    }
    return (false);
}

void my_setenv(command *arg, char *name, char *str)
{
    int i = 0;
    bool found = false;

    for (i = 0; arg->env && arg->env[i] && !found; i++)
        found = detect_name(arg->env[i], name);
    if (found) {
        if (i > 0)
            i--;
        arg->env[i] = malloc(sizeof(char) *
        (my_strlen(name) + my_strlen(str) + 1));
        arg->env[i] = my_strcat(name, "=");
        arg->env[i] = my_strcat(arg->env[i], str);
    }
    else if (!found)
        add_line(arg, name, str);
}

bool detect_if_setenv(command *arg2, char *str)
{
    int j = 0;
    int i = 0;
    char *arg = malloc(sizeof(char) * (my_strlen(str) + 2));
    char **args = NULL;

    for (i = 0; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    for (j = 0; str && str[i] && str[i] != ' ' && str[i] != '\t'; i++) {
        arg[j] = str[i];
        j++;
    }
    arg[j] = 0;
    if (my_strcmp(arg, "setenv") == 0) {
        args = detect_setenv_args(arg2, i, str);
        if (args && !args[2])
            my_setenv(arg2, args[0], args[1]);
        else if (args && args[2])
            my_puterror("setenv: Too many arguments.\n");
        return (true);
    }
    free(arg);
    return (false);
}

bool detect_if_env(command *args, char *str)
{
    int j = 0;
    int i = 0;
    char *arg = malloc(sizeof(char) * (my_strlen(str) + 2));

    for (i = 0; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    for (j = 0; str && str[i] && str[i] != ' ' && str[i] != '\t'; i++) {
        arg[j] = str[i];
        j++;
    }
    arg[j] = 0;
    if (my_strcmp(arg, "env") == 0) {
        disp_env(args);
        return (true);
    }
    free(arg);
    return (false);
}
