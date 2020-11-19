/*
** EPITECH PROJECT, 2019
** my_unsetenv
** File description:
** my_unsetenv
*/

#include "my.h"
#include "minishell.h"

bool detect_if_unsetenv(command *args, char *str)
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
    if (my_strcmp(arg, "unsetenv") == 0) {
        return (true);
    }
    free(arg);
    return (false);
}
