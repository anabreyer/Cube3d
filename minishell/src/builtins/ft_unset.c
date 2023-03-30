/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:15:30 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 23:25:12 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_unset(t_tools *tools, char **args)
{
    int i;
    int pos;
    int exit;

    exit = EXIT_SUCCESS;
    i = 1;
    while (args[i])
    {
        if (!check_env_var_name(args[i]) || ft_strchr(args[i], '=') != NULL)
        {
            error_msg("unset", args[i], "not a valid identifier", 0);
            exit = EXIT_FAILURE;
        }
        else
        {
            pos = env_position(tools->envp, args[i]);
            if (pos != -1)
                env_remove(tools, pos);
        }
        i++;
    }
    return (exit);
}