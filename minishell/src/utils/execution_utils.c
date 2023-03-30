/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:31:15 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/28 18:19:39 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

int check_if_directory(char *cmd)
{
    struct stat cmd_stat;

    ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
    stat(cmd, &cmd_stat);
    return (S_ISDIR(cmd_stat.st_mode));
}

int command_not_found(t_tools *tools, t_cmd *cmd)
{
    if (ft_strchr(cmd->cmd, '/') == NULL && env_position(tools->envp, "PATH") != 1)
        return (error_msg(cmd->cmd, NULL, "command not found", ERR_CMD_NOT_FOUND));
    if (access(cmd->cmd, F_OK) != 0)
        return (error_msg(cmd->cmd, NULL, strerror(errno), ERR_CMD_NOT_FOUND));
    else if (check_if_directory(cmd->cmd))
        return (error_msg(cmd->cmd, NULL, "is a directory", ERR_CMD_NOT_EXECUTABLE));
    else if (access(cmd->cmd, F_OK | X_OK) != 0)
        return (error_msg(cmd->cmd, NULL, strerror(errno), ERR_CMD_NOT_EXECUTABLE));
    return (EXIT_SUCCESS);
}