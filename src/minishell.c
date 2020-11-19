/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell
*/

#include "minishell.h"

bool parse_errors(int ac, char **av, command *arg)
{
    if (ac < 2) {
        my_puterror("not enough arguments\n");
        return (false);
    }
    if (ac > 2) {
        my_puterror("too much arguments\n");
        return (false);
    }
    if (arg == NULL)
        return (false);
    return (true);
}

void copy_args(char **av, command *arg)
{
    int i = 0;
    int j = 0;
    int k = 0;

    arg->args[0] = malloc(sizeof(char) * my_strlen(av[1]));
    for (j = 0; av && av[1] && av[1][i]; i++) {
        if (av[1][i] && av[1][i] == ' ' || av[1][i] == '\t') {
            arg->args[j][k] = 0;
            j++;
            k = 0;
            arg->args[j] = malloc(sizeof(char) * my_strlen(av[1]));
        }
        for (;av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'); i++);
        arg->args[j][k] = av[1][i];
        k++;
    }
}

char **copy_env(char **ae)
{
    char **env = NULL;
    int nb = 0;
    int i = 0;

    for (nb = 0; ae && ae[nb]; nb++);
    env = malloc(sizeof(char *) * (nb + 1));
    if (env == NULL || nb == 0)
        return (NULL);
    for (i = 0; ae && ae[i]; i++)
        env[i] = my_strdup(ae[i]);
    env[i] = NULL;
    return (env);
}

bool detect_prog(char **av, command *arg)
{
    int i = 0;

    if (av && av[1]) {
        arg->name = malloc(sizeof(char) * my_strlen(av[1]));
        arg->args = malloc(sizeof(char *) * my_strlen(av[1]));
    }
    if (arg->name == NULL || arg->args == NULL)
        return (false);
    for (i = 0; av && av[1] && av[1][i] &&
    av[1][i] != ' ' && av[1][i] != '\t'; i++) {
        arg->name[i] = av[1][i];
    }
    arg->name[i] = 0;
    copy_args(av, arg);
    return (true);
}

int minishell(int ac, char **av, char **ae)
{
    command *arg = malloc(sizeof(command));
    bool work = true;

    arg->env = copy_env(ae);
    arg->prev = NULL;
    while (work && arg->env) {
        if (isatty(0) == 1)
            my_putstr("$> ");
        arg->instance = NULL;
        work = disp_prompt(arg);
    }
    return (MY_EXIT_SUCCESS);
}
