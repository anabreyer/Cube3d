/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:26:31 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/29 23:13:02 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int pwd_init(t_tools *tools)
{
    char buffer[PATH_MAX];
    char *pwd;

    pwd = getcwd(buffer, PATH_MAX);
    tools->pwd = ft_strdup(pwd);
    if (!tools->pwd)
        return (0);
    if (env_position(tools->envp, "OLDPWD") != -1)
    {
        tools->oldpwd = ft_strdup(env_value(tools->envp, "OLSPWD"));
        if (!tools->oldpwd)
            return (0);
    }
    else 
    {
        tools->oldpwd = ft_strdup(pwd);
        if (!tools->oldpwd)
            return (0);
    }
    return (0);
}

static int env_init(t_tools *tools, char **env)
{
    int i;
    
    tools->envp = ft_calloc(count_env(env) + 1, sizeof * tools->envp);
    if (!tools->envp)
        return (0);
    i = 0;
    while (env[i])
    {
        tools->envp[i] = ft_strdup(env[i]);
        if (!tools->envp[i])
            return (0);
        i++;
    }
    return (1);
}

int tools_init(t_tools *tools, char **env)
{
    if (!env_init(tools, env))
    {
        error_msg("Fatal", NULL, "Could not initialize enviroment", 1);
        return (0);
    }
    if (!pwd_init(tools))
    {
        error_msg("Fatal", NULL, "could not imitialize working directories", 1);
        return (0);
    }
    tools->tokens = NULL;
    tools->u_input = NULL;
    tools->cmd = NULL;
    tools->pid = -1;
    g_exit_code = 0;
    return (1);
}

void file_init(t_cmd *cmd)
{
    if (!cmd->files)
    {
        cmd->files = malloc(sizeof *cmd->files);
        if(!cmd->files)
            return ;
        cmd->files->fd_in = -1;
        cmd->files->fd_out = -1;
        cmd->files->stdin_backup = -1;
        cmd->files->stdou_backup = -1;
        cmd->files->infile = NULL;
        cmd->files->outfile = NULL;
        cmd->files->heredoc_quotes = 0;
        cmd->files->heredoc_limit = NULL;
    }
}

void exit_shell(t_tools *tools, int exno)
{
    if (tools)
    {
        if (tools->cmd && tools->cmd->files)
            close_file(tools->cmd, 1);
        free_tools(tools, 1);
    }
    exit(exno);
}