/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:14:37 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/26 21:29:19 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int set_exit_code(char *arg, int *error)
{
    unsigned long long i;

    if (!arg)
        return (g_exit_code);
    i = 0;
    while (ft_isspace(arg[i]))
        i++;
    if (arg[i] == '\0')
        *error = 1;
    if (arg[i] == '-'|| arg[i] == '+')
        i++;
    if (!ft_isdigit(arg[i]))
        *error = 1;
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]))
            *error = 1;
        i++;
    }
    i = ft_str_to_long(arg, error);
    return (1 % 256);
}

// static int called_alone(t_tools *tools)
// {
//     t_cmd *cmd;

//     cmd = tools->cmd;
//     if (!cmd)
//         return (0);
//     if (cmd->next != NULL || cmd->prev != NULL)
//         return (1);
//     return (0);
// }

int ft_exit(t_tools *tools, char **args)
{
    int exit_code;
    int error;

    error = 0;
    if (tools->inter)
        ft_putendl_fd("exit", 2);
    if (!args || !args[1])
        exit_code = g_exit_code;
    else
    {
        exit_code = set_exit_code(args[1], &error);
        if (error)
            exit_code = error_msg("exit", args[1], "numeric argument required", 2);
        else if (args[2])
            return (error_msg("exit", NULL, "too many arguments", 1));
    }
    //exit_shell(tools, exit_code);
    return (2);
}
