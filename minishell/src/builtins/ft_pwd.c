/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:11:30 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 23:14:39 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_pwd(t_tools *tools, char **args)
{
    char buffer[PATH_MAX];
    char *cwd;

    (void)args;
    if (tools->pwd)
    {
        ft_putendl_fd(tools->pwd, STDOUT_FILENO);
        return (EXIT_SUCCESS);
    }
    cwd = getcwd(buffer, PATH_MAX);
    if (cwd)
    {
        ft_putendl_fd(cwd, STDOUT_FILENO);
        return (EXIT_SUCCESS);
    }
    error_msg("pwd", NULL, strerror(errno), errno);
    return (EXIT_FAILURE);
}