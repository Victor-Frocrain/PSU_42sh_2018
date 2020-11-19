/*
** EPITECH PROJECT, 2019
** disp_env
** File description:
** disp_env
*/

#include "my.h"
#include "minishell.h"

char *strcpy_until_dot(char *str1, char *str2)
{
    str1 = malloc(sizeof(char) * my_strlen(str2));
    if (str1 == NULL)
        return (NULL);
    for (int i = 0; str2 && str2[i] && str2[i] != '.'; i++)
        str1[i] = str2[i];
    return (str1);
}

void clean_strings(char **ae, char **params)
{
    int i = 0;
    char **buff = malloc(sizeof(char *) * 4);
    int j = 6;

    if (ae == NULL)
        return;
    for (int k = 0; ae && ae[j] && j <= 9; i++) {
        for (k = 0; ae[j][k] && ae[j][k] != '='; k++);
        params[i] = strcpy_until_dot(params[i], ae[j] + k + 1);
        if (params[i] == NULL)
            return;
        j += 3;
    }
}

void disp_env(command *arg)
{
    for (int i = 0; arg->env && arg->env[i]; i++) {
        my_putstr(arg->env[i]);
        my_putchar('\n');
    }
}

bool detect_cases(command *arg, char *str)
{
    if (detect_if_cd(arg, str) == false &&
        detect_if_setenv(arg, str) == false &&
        detect_if_env(arg, str) == false &&
        detect_if_unsetenv(arg, str) == false)
        return (false);
    return (true);
}
