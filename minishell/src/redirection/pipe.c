/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:38:24 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/29 23:08:25 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void close_pipe(t_cmd *cmd, t_cmd *skip_cmd)
{
    while (cmd)
    {
        if (cmd != skip_cmd && cmd->pipe)
        {
            close(cmd->pipe[0]);
            close(cmd->pipe[1]);
        }
        cmd = cmd->next;
    }
}

int create_pipe(t_tools *tools)
{
    int *fd;
    t_cmd *tmp;

    tmp = tools->cmd;
    while (tmp)
    {
        if (tmp->pipe_out || (tmp->prev && tmp->prev->pipe_out))
        {
            fd = malloc(sizeof * fd * 2);
            if (!fd || pipe(fd) != 0)
            {
                free_tools(tools, 0);
                return (0);
            }
            tmp->pipe = fd;
        }
        tmp = tmp->next;
    }
    return (1);
}

int set_pipe(t_cmd *cmd, t_cmd *c)
{
    if (!c)
        return (0);
    if (c->prev && c->prev->pipe_out)
        dup2(c->prev->pipe[0], STDIN_FILENO);
    if (c->pipe_out)
        dup2(c->pipe[1], STDOUT_FILENO);
    close_pipe(cmd, c);
    return (1);
}