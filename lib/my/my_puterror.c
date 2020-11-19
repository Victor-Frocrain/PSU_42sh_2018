/*
** EPITECH PROJECT, 2019
** my_puterror
** File description:
** my_puterror
*/

#include "my.h"

void my_puterror(char *str)
{
    for (int i = 0; str && str[i]; i++)
        write(2, &str[i], 1);
}
