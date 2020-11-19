/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** convert a string to digit
*/

int my_length(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int built_str2(char *str2, int neg, int j)
{
    int result = 0;
    int dec = 1;

    if ((my_length(str2) == 10 && str2[0] >= '2') || my_length(str2) > 10)
        return (0);
    j--;
    while (str2[j]) {
        result = result + ((str2[j] - '0') * dec);
        dec = dec * 10;
        j--;
    }
    result = result * neg;
    return (result);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    int length = my_length(str);
    char str2[length];
    int neg = 1;

    if (!str[0])
        return (0);
    while (str[i] > '9' || str[i] < '0')
        i++;
    if (str[i - 1] == '-')
        neg = -1;
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        str2[j] = str[i];
        i++;
        j++;
    }
    str2[j] = '\0';
    return (built_str2(str2, neg, j));
}
