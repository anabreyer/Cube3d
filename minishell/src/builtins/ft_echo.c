/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:49:54 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 23:26:38 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void print_lines(char **args, int option, int i)
{
    if (!args[i])
    {
        if (!option)
            ft_putchar_fd('\n', STDOUT_FILENO);
        return ;
    }
    while (args[i])
    {
        ft_putstr_fd(args[i], STDOUT_FILENO);
        if (args[i + 1])
            ft_putchar_fd(' ', STDOUT_FILENO);
        else if (!args[i + 1] && !option)
            ft_putchar_fd('\n', STDOUT_FILENO);
        i++;
    }
}

static int detect_n(char *arg)
{
    int i;
    int option;

    option = 0;
    i = 0;
    if (arg[i] != '-')
        return (option);
    i++;
    while(arg[i] && arg[i] == 'n')
        i++;
    if (arg[i] == '\0')
        option = 1;
    return (option);
}

int ft_echo(t_tools *tools, char **args)
{
    int option;
    int i;
    
    (void)tools;
    option = 0;
    i = 1;
    while (args[i] && detect_n(args[i]))
    {
        option = 1;
        i++;
    }
    print_lines(args, option, i);
    return (EXIT_SUCCESS);
}