/*
** EPITECH PROJECT, 2019
** my_exit
** File description:
** my_exit
*/

#include "my.h"
#include "minishell.h"

bool detect_if_exit(char *str)
{
    int j = 0;
    int i = 0;
    char *arg = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (i = 0; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    for (j = 0; str && str[i] && str[i] != ' ' && str[i] != '\t'; i++) {
        arg[j] = str[i];
        j++;
    }
    arg[j] = 0;
    if (my_strcmp(arg, "exit") == 0) {
        my_putstr("exit\n");
        return (true);
    }
    return (false);
}
