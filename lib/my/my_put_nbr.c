/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Print the integers
*/

#include <unistd.h>

void my_putchar2(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int i = 0;
    unsigned long j = 10;
    unsigned int nb2 = 0;

    if (nb < 0) {
        my_putchar2('-');
        nb = nb * (-1);
    }
    nb2 = nb;
    for (unsigned int copy = nb2; copy / 10 > 0; copy = copy / 10) {
        i++;
        j = j * 10;
    }
    while (i >= 0) {
        my_putchar2((nb2 % j) / (j / 10) + '0');
        j = j / 10;
        i--;
    }
    return (0);
}
