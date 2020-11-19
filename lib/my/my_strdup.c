/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (result == NULL)
        return (NULL);
    for (i = 0; str && str[i]; i++)
        result[i] = str[i];
    result[i] = 0;
    return (result);
}
