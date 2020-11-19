/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *str1, char *str2)
{
    int l1 = my_strlen(str1);
    int l2 = my_strlen(str2);
    int i = 0;
    char *result = malloc(sizeof(char) * (l1 + l2 + 1));

    for (int j = 0; str1 && str1[j]; j++) {
        result[i] = str1[j];
        i++;
    }
    for (int j = 0; str2 && str2[j]; j++) {
        result[i] = str2[j];
        i++;
    }
    result[i] = 0;
    return (result);
}
