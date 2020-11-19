/*
** EPITECH PROJECT, 2019
** check_access
** File description:
** check_access
*/

#include "my.h"
#include "minishell.h"

bool check_if_bin(char *str, char *name)
{
    if (access(str, F_OK) == -1) {
        my_puterror(name);
        my_puterror(": Command not found.\n");
        return (false);
    }
    else if (access(str, X_OK) == -1) {
        my_puterror(name);
        my_puterror(": Permission denied.\n");
        return (false);
    }
    return (true);
}

bool check_access(char *str, char *name)
{
    DIR *rd = NULL;
    struct stat info;

    if ((rd = opendir(str)) != NULL) {
        my_puterror(name);
        my_puterror(": Permission denied.\n");
        closedir(rd);
        return (false);
    }
    stat(str, &info);
    if (info.st_mode == S_IFDIR) {
        my_puterror(name);
        my_puterror(": Permission denied.\n");
        return (false);
    }
    return (check_if_bin(str, name));
}
