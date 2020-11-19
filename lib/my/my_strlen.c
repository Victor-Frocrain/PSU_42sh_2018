/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** count the length of string
*/

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str && str[i]; i++);
    return (i);
}
