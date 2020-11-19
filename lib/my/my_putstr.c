/*
** EPITECH PROJECT, 2018
** my_put_str.c
** File description:
** displays characters
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str && str[i]; i++)
        my_putchar(str[i]);
    return (0);
}
