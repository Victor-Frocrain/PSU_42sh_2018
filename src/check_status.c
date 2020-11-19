/*
** EPITECH PROJECT, 2019
** check_status
** File description:
** check_status
*/

#include "my.h"
#include "minishell.h"

void check_status(int status)
{
    int signal = 0;

    if (status < 0)
        exit(MY_EXIT_ERROR);
    if (WIFSIGNALED(status)) {
        signal = WTERMSIG(status);
        signal != SIGFPE?my_puterror(strsignal(signal)):
        my_puterror("Floating exception");
        my_puterror("\n");
    }
}
