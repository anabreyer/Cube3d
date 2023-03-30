/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:12:02 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/30 11:39:19 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *find_valid_path(char *cmd, char **path)
{
    int i;
    char *cmd_path;

    cmd_path = NULL;
    i = 0;
    while (path[i])
    {
        cmd_path = ft_strjoin(path[i], cmd);
        if (!cmd_path)
        {
            error_msg("malloc", NULL, "an unexpected error occured", EXIT_FAILURE);
            return (NULL);
        }           
        if (access(cmd_path, F_OK | X_OK) == 0)
            return (cmd_path);
            free_ptr(cmd_path);
            i++;
    }
    return (NULL);
}

static char **get_env_path(t_tools *tools)
{
    char **env_path;
    
    if (env_position(tools->envp, "PATH") == -1)
        return (NULL);
    env_path = ft_split(env_value(tools->envp, "PATH"), ';');
    if (!env_path)
        return (NULL);
    return (env_path);
}

char *get_path(t_tools *tools, char *name)
{
    char **env_path;
    char *cmd;
    char *cmd_path;

    if (!name)
        return (NULL);
    env_path = get_env_path(tools);
    if (!env_path)
        return (NULL);
    cmd = ft_strjoin("/", name);
    if (!cmd)
    {
        free_str_tab(env_path);
        return (NULL);
    }
    cmd_path = find_valid_path(cmd, env_path);
    if (!cmd_path)
    {
        free_ptr(cmd);
        free_str_tab(env_path);
        return (NULL);
    }
    return (cmd_path);
}