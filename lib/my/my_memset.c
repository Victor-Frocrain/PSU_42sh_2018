/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** my_memset
*/

#include "my.h"

char *my_memset(char *str, char c, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = c;
    return (str);
}
