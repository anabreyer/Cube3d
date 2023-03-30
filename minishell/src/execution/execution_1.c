/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:28:20 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/30 11:40:04 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

int g_exit_code;

static int get_child(t_tools *tools)
{
    pid_t wpid;
    int status;
    int save_status;

    close_file(tools->cmd, 0);
    save_status = 0;
    wpid = 0;
    while(wpid != -1 || errno != ECHILD)
    {
        wpid = waitpid(-1, &status, 0);
        if (wpid == tools->pid)
            save_status = status;
        continue;
    }
    if (WIFSIGNALED(save_status))
        status = 128 + WTERMSIG(save_status);
    else if (WIFEXITED(save_status))
        status = WEXITSTATUS(save_status);
    else
        status = save_status;
    return (status);
}

static int create_child(t_tools *tools)
{
    t_cmd *cmd;


    cmd = tools->cmd;
    while(tools->pid != 0 && cmd)
    {
        tools->pid = fork();
        if(tools->pid == -1)
            return (error_msg("fork", NULL, strerror(errno), EXIT_FAILURE));
        else if (tools->pid == 0)
            execute_cmd(tools, cmd);
        cmd = cmd->next;
    }
    return (get_child(tools));
}

static int preparation(t_tools *tools)
{
    if (!tools || !tools->cmd)
        return (EXIT_SUCCESS);
    if (!tools->cmd->cmd)
    {
        if (tools->cmd->files && !check_correct(tools->cmd->files))
            return (EXIT_FAILURE);
        return (EXIT_SUCCESS);
    }
    return (ERR_CMD_NOT_FOUND);
}

int execute(t_tools *tools)
{
    int ret;

    ret = preparation(tools);
    if (ret != ERR_CMD_NOT_FOUND)
        return (ret);
    if (!tools->cmd->pipe_out && !tools->cmd->prev && check_correct(tools->cmd->files))
    {
        redirect_files(tools->cmd->files);
        ret = builtins(tools, tools->cmd);
        restore_files(tools->cmd->files);
    }
    if (ret != ERR_CMD_NOT_FOUND)
        return (ret);
    return (create_child(tools));
}
