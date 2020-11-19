/*
** EPITECH PROJECT, 2019
** exec_prog
** File description:
** exec_prog
*/

#include "minishell.h"

void exec_child(command *arg, int status, char **ae)
{
    pid_t pid = fork();
    pid_t w;

    if (pid == 0) {
        my_putstr("Child PID: ");
        my_put_nbr(getpid());
        my_putchar('\n');
        execve(arg->name, arg->args, ae);
    }
    else {
        w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
        my_putstr("Program terminated.\nStatus: ");
    }
}

void print_sets(command *arg, int status, char **ae)
{
    int i = 0;
    pid_t pid = getpid();

    for (i = 0; arg->args[i]; i++);
    my_putstr("Program name:  ");
    my_putstr(arg->name);
    my_putstr("\nNb args:  ");
    my_put_nbr(i - 1);
    my_putstr("\nPID: ");
    my_put_nbr(pid);
    my_putchar('\n');
}

void exec_prog(command *arg, char **ae)
{
    int status = 0;

    print_sets(arg, status, ae);
    exec_child(arg, status, ae);
}
