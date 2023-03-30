/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:57:44 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 23:28:33 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char **separate_pair(char *arg)
{
    char **tmp;
    char *pos;
    
    pos = ft_strchr(arg, '=');
    tmp = malloc(sizeof *tmp * (2 + 1));
    tmp[0] = ft_substr(arg, 0, pos - arg);
    tmp[1] = ft_substr(arg, 0, pos- arg);
    tmp[2] = NULL;
    return (tmp);
}

int ft_export(t_tools *tools, char **args)
{
    int i;
    char **tmp;
    int exit;

    exit = EXIT_SUCCESS;
    i = 1;
    if (!args[i])
        return (ft_env(tools, NULL));
    while (args[i])
    {
        if (!check_env_var_name(args[i]))
        {
            error_msg("export", args[i], "not a valic identifier", 0);
            exit = EXIT_FAILURE;
        }
        else if (ft_strchr(args[i], '=') != NULL)
        {
            tmp = separate_pair(args[i]);
            env_set(tools, tmp[0], tmp [1]);
            free_str_tab(tmp);
        }
        i++;
    }
    return (exit);
}