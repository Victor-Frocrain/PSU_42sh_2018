/*
** EPITECH PROJECT, 2019
** manage_cd
** File description:
** manage_cd
*/

#include "my.h"
#include "minishell.h"

void display_error(char *str)
{
    int ac = access(str, F_OK);
    int ex = access(str, R_OK);

    if (str && ex == -1 && ac == 0) {
        my_puterror(str);
        my_puterror(": Permission denied.\n");
    }
    else if (str && ac == 0) {
        my_puterror(str);
        my_puterror(": Not a directory.\n");
    }
    else if (str) {
        my_puterror(str);
        my_puterror(": No such file or directory.\n");
    }
}

char *cut_str(char *str)
{
    int i = 0;
    int j = 1;
    char *buff = malloc(sizeof(str) + 1);
    DIR *dir = NULL;

    if (buff)
        buff[0] = '/';
    dir = opendir(str);
    if (dir == NULL) {
        display_error(str);
        return (NULL);
    }
    for (j = 1; buff && str && str[i]; j++) {
        buff[j] = str[i];
        i++;
    }
    buff[j] = 0;
    closedir(dir);
    return (buff);
}

bool apply_cd(command *args, char *name, char *arg)
{
    if (my_strcmp(name, "cd") == 0) {
        modify_path(args, arg);
        return (true);
    }
    return (false);
}

bool detect_if_cd(command *args, char *str)
{
    int j = 0;
    int i = 0;
    char *arg = malloc(sizeof(char) * (my_strlen(str) + 2));
    char *arg2 = malloc(sizeof(char) * (my_strlen(str) + 2));

    for (i = 0; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    for (j = 0; str && str[i] && str[i] != ' ' && str[i] != '\t'; i++) {
        arg[j] = str[i];
        j++;
    }
    arg[j] = 0;
    for (; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    for (j = 0; str && str[i] && str[i] != ' ' && str[i] != '\t'; i++) {
        arg2[j] = str[i];
        j++;
    }
    arg2[j + 1] = 0;
    return (apply_cd(args, arg, arg2));
}
