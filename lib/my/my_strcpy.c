/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy str
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src && src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
