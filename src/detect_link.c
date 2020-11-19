/*
** EPITECH PROJECT, 2019
** detect_link
** File description:
** detect_link
*/

#include "my.h"
#include "minishell.h"

bool detect_link(command *arg, char *str)
{
    int j = 0;

    for (int i = 0; str && str[i]; j++) {
        if ((arg->instance = my_taballoc(arg->instance)) == NULL)
            return (false);
        if ((arg->instance[j] = malloc(sizeof(char) * my_strlen(str))) == NULL)
            return (false);
        for (; str[i] == ' ' || str[i] == '\t'; i++);
        for (int k = 0; str[i] && str[i] != ';'; k++) {
            arg->instance[j][k] = str[i];
            i++;
        }
        i++;
    }
    return (true);
}
