/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:00 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/30 11:34:38 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

int builtins(t_tools *tools, t_cmd *cmd)
{
    int ret;

    ret = ERR_CMD_NOT_FOUND;
    if (ft_strncmp(cmd->cmd, "cd", 3) == 0)
        ret = ft_cd(tools, cmd->args);
    else if (ft_strncmp(cmd->cmd, "echo", 5) == 0)
        ret = ft_echo(tools, cmd->args);
    else if (ft_strncmp(cmd->cmd, "env", 4) == 0)
        ret = ft_env(tools, cmd->args);
    else if (ft_strncmp(cmd->cmd, "export", 7) == 0)
        ret = ft_export(tools, cmd->args);
    else if (ft_strncmp(cmd->cmd, "pwd", 4) == 0)
        ret = ft_pwd(tools, cmd->args);
    else if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
        ret = ft_unset(tools, cmd->args);
    else if (ft_strncmp(cmd->cmd, "exit", 5) == 0)
        ret = ft_exit(tools, cmd->args);
    return (ret);
}

static int system_bin(t_tools *tools, t_cmd *cmd)
{
    if (!cmd->cmd || cmd->cmd[0] == '\0')
        return (ERR_CMD_NOT_FOUND);
    if (check_if_directory(cmd->cmd))
        return (ERR_CMD_NOT_FOUND);
    cmd->path = get_path(tools, cmd->cmd);
    if (!cmd->path)
        return (ERR_CMD_NOT_FOUND);
    if (execve(cmd->path, cmd->args, tools->envp) == -1)
        error_msg("execve", NULL, strerror(errno), errno);
    return (EXIT_FAILURE);
}

static int local_bin(t_tools *tools, t_cmd *cmd)
{
    int ret;

    ret = command_not_found(tools, cmd);
    if (ret != 0)
        return (ret);
    if (execve(cmd->cmd, cmd->args, tools->envp) == -1)
        return (error_msg("execve", NULL, strerror(errno), errno));
    return (EXIT_FAILURE);
}

int execute_cmd(t_tools *tools, t_cmd *cmd)
{
    int ret;
    
    if (!cmd || !cmd->cmd)
        exit_shell(tools, error_msg("child", NULL, "parsing error: no command to execute", EXIT_FAILURE));
    if (!check_correct(cmd->files))
        exit_shell(tools, EXIT_FAILURE);
    set_pipe(tools->cmd, cmd);
    redirect_files(cmd->files);
    close_file(tools->cmd, 0);
    if (ft_strchr(cmd->cmd, '/') == NULL)
    {
        ret = builtins(tools, cmd);
        if (ret != ERR_CMD_NOT_FOUND)
            exit_shell(tools, ret);
        ret = system_bin(tools, cmd);
        if (ret != ERR_CMD_NOT_FOUND)
            exit_shell(tools, ret);
    }
    ret = local_bin(tools, cmd);
    exit_shell(tools, ret);
    return (ret);
}
