/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:08:18 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 19:14:16 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_env(t_tools *tools, char **args)
{
    int i;
    
    if (args && args[1])
        return (error_msg("env", NULL, "too many arguments", 2));
    i = 0;
    if (!tools->envp)
        return (EXIT_FAILURE);
    while (tools->envp[i])
        ft_putendl_fd(tools->envp[i++], STDOUT_FILENO);
    return (EXIT_SUCCESS);
}