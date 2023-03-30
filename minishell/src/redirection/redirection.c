/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:46:46 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/29 23:21:35 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

int check_correct(t_files *files)
{
    if (!files || (!files->infile && !files->outfile))
        return (1);
    if ((files->infile && files->fd_in == -1) || (files->outfile && files->fd_out == -1))
        return (0);
    return (1);
}

int redirect_files(t_files *files)
{
    int ret;
    
    ret = 1;
    if (!files)
        return (ret);
    files->stdin_backup = dup(STDIN_FILENO);
    if (files->stdin_backup == -1)
        ret = error_msg("dup", "stdin backup", strerror(errno), 0);
    files->stdou_backup = dup(STDOUT_FILENO);
    if (files->stdou_backup == -1)
        ret = error_msg("dup", "stdout backup", strerror(errno), 0);
    if (files->fd_in != -1)
    {
        if (dup2(files->fd_in,STDIN_FILENO) == -1)
            ret = error_msg("dup2", files->infile, strerror(errno), 0);
    }
    if (files->fd_out != -1)
    {
        if (dup2(files->fd_out,STDOUT_FILENO) == -1)
            ret = error_msg("dup2", files->outfile, strerror(errno), 0);
    }
    return (ret);
}

int restore_files(t_files *files)
{
    int ret;

    ret = 1;
    if (!files)
        return (ret);
    if (files->stdin_backup != -1)
    {
        if (dup2(files->stdin_backup, STDIN_FILENO) == -1)
            ret = 0;
        close(files->stdin_backup);
        files->stdin_backup = -1;
    }
    if (files->stdou_backup != -1)
    {
        if (dup2(files->stdou_backup, STDIN_FILENO) == -1)
            ret = 0;
        close(files->stdou_backup);
        files->stdou_backup = -1;
    }
    return (ret);
}