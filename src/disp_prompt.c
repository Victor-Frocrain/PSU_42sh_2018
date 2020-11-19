/*
** EPITECH PROJECT, 2019
** disp_prompt
** File description:
** disp_prompt
*/

#include "my.h"
#include "minishell.h"
#include "get_next_line.h"

char *clean_begining(char *str)
{
    int j = 0;
    int i = 0;
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (result == NULL)
        return (NULL);
    for (j = 0; str && str[j] && (str[j] == ' ' || str[j] == '\t'); j++);
    for (i = 0; str[j]; j++) {
        result[i] = str[j];
        i++;
    }
    result[i] = 0;
    return (result);
}

bool cut_string(char *str, int spaces, command *arg)
{
    int i = 0;

    arg->args = malloc(sizeof(char *) * (spaces + 1));
    if (arg->args == NULL)
        return (false);
    arg->args[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i = 0; str && str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
    arg = list_args(str, arg, i);
    if (arg == NULL)
        return (false);
    for (i = 0; arg->args[i]; i++)
        if (my_strlen(arg->args[i]) == 0)
            arg->args[i] = NULL;
    return (true);
}

char *manage_name(char *str, command *arg)
{
    bool redirect = false;
    int spaces = 1;

    if ((str = clean_begining(str)) == NULL || detect_if_exit(str))
        return (NULL);
    if (my_strlen(str) == 0)
        return (str);
    for (int i = 0; str && str[i]; i++)
        if (str[i] == ' ')
            spaces++;
    if (cut_string(str, spaces, arg) == false)
        return (NULL);
    for (int i = 0; str && str[i]; i++)
        if (str[i] == ' ' || str[i] == '\t')
            str[i] = 0;
    for (int i = 0; str && str[i]; i++)
        if (str[i] == '/')
            redirect = true;
    if (redirect == false)
        str = search_bin(arg, str);
    return (str);
}

bool exec_prompt(char *str, command *arg, pid_t pid, int status)
{
    char *name = my_strdup(str);

    if (detect_cases(arg, str) == false) {
        str = manage_name(str, arg);
        if (str == NULL)
            return (false);
        if (my_strlen(str) == 0)
            return (true);
        if (check_access(str, name) == false)
            return (true);
        if ((pid = fork()) == 0)
            status = execve(str, arg->args, arg->env);
        else {
            waitpid(pid, &status, WUNTRACED | WCONTINUED);
            check_status(status);
        }
    }
    return (true);
}

bool disp_prompt(command *arg)
{
    char *str = get_next_line(0);
    pid_t pid = 0;
    static int status = 0;
    int i = 0;

    if (str == NULL)
        return (false);
    if (detect_link(arg, str) == false)
        return (false);
    for (i = 0; arg->instance && arg->instance[i]; i++) {
        if (exec_prompt(arg->instance[i], arg, pid, status) == false)
            return (false);
    }
    return (true);
}
