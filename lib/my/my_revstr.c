/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse string
*/

int my_count(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_count(str) - 1;
    int j = 0;
    char c;

    while (j <= i) {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
        i--;
        j++;
    }
    return (str);
}
