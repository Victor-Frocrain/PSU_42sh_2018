/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void update_buff(char *buff, int jump, int red)
{
    for (int i = 0; buff[i]; i++) {
        if (buff[jump] && jump < red)
            buff[i] = buff[jump];
        else {
            buff[i] = 0;
            return;
        }
        jump++;
    }
}

char *my_realloc(char *result, int size)
{
    int i = 0;
    int size_result = 0;
    char *new = NULL;

    for (size_result = 0; result && result[size_result]; size_result++);
    new = malloc(sizeof(char) * (size_result + size + 1));
    for (int j = 0; j < size_result + size + 1; j++)
        new[j] = 0;
    for (i = 0; result && result[i]; i++)
        new[i] = result[i];
    new[i] = 0;
    return (new);
}

char *copy_buff(char *buff, char *result, bool *copy, int max)
{
    int size_result = 0;
    int size_buff = 0;
    int i = 0;

    for (size_result = 0; result && result[size_result]; size_result++);
    for (size_buff = 0; buff && buff[size_buff]; size_buff++);
    result = my_realloc(result, size_buff);
    for (i = 0; buff[i]; i++) {
        if (buff[i] == '\n' || i >= max) {
            result[size_result] = 0;
            *copy = true;
            break;
        }
        result[size_result] = buff[i];
        size_result++;
    }
    result[size_result] = 0;
    return (result);
}

char *fill_buff(char *buff, char *result, int fd, int *red)
{
    bool copy = false;

    if (buff == NULL) {
        buff = malloc(sizeof(char) * (READ_SIZE + 1));
        for (int i = 0; i < READ_SIZE + 1; i++)
            buff[i] = 0;
        return (buff);
    }
    *red = read(fd, buff, READ_SIZE);
    if (*red == 0)
        result = copy_buff(buff, result, &copy, *red);
    while (*red != 0 && copy == false) {
        if (*red < 0)
            return (NULL);
        result = copy_buff(buff, result, &copy, *red);
        if (copy == false)
            *red = read(fd, buff, READ_SIZE);
    }
    return (result);
}

char *get_next_line(int fd)
{
    char *result = NULL;
    static char *buff = NULL;
    bool copy = false;
    int jump = 0;
    static int red = 0;

    if (buff == NULL && READ_SIZE <= 2147483647)
        buff = fill_buff(buff, result, fd, &red);
    else if (READ_SIZE <= 2147483647) {
        for (jump = 0; buff[jump] && buff[jump] != '\n'; jump++);
        update_buff(buff, jump + 1, red);
    }
    if (fd < 0 || red < 0 || buff == NULL || READ_SIZE < 0)
        return (NULL);
    result = copy_buff(buff, result, &copy, READ_SIZE);
    if (copy == false && result)
        result = fill_buff(buff, result, fd, &red);
    if (result == NULL || (result && !result[0] && !buff[0]))
        return (NULL);
    return (result);
}
