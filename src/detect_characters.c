/*
** EPITECH PROJECT, 2019
** detect_characters
** File description:
** detect_characters
*/

#include "my.h"
#include "minishell.h"

bool detect_characters(char *str)
{
    if (str && str[0] && ((str[0] < 'a' || str[0] > 'z') &&
    (str[0] < 'A' || str[0] > 'Z'))) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (false);
    }
    for (int i = 1; str && str[i]; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
        (str[i] < '1' || str[i] > '9')) {
            my_putstr("setenv: Variable name must contain alphanumeric ");
            my_putstr("characters.\n");
            return (false);
        }
    }
    return (true);
}
