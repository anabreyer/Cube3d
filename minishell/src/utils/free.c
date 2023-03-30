/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:29:08 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/29 23:12:19 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void free_ptr(void *ptr)
{
    if(ptr != NULL)
    {
        free(ptr);
        ptr = NULL;
    }
}

void free_str_tab(char **tab)
{
    int i;

    i = 0;
    if (tab)
    {
        while (tab[i])
        {
            if (tab[i])
            {
                free_ptr(tab[i]);
                tab[i] = NULL;
            }
            i++;
        }
        free(tab);
        tab = NULL;
    }
}

void free_files(t_files *files)
{
    if (!files)
        return ;
    restore_files(files);
    if (files->heredoc_limit)
    {
        unlink(files->infile);
        free_ptr(files->heredoc_limit);
    }
    if (files->infile)
        free_ptr(files->infile);
    if (files->outfile)
        free_ptr(files->outfile);
    if (files)
        free_ptr(files);
}

void free_tools(t_tools *tools, int clear)
{
    if (tools && tools->u_input)
    {
        free_ptr(tools->u_input);
        tools->u_input = NULL;
    }
    if (tools && tools->tokens)
        //lstclear_token(&tools->tokens, &free_ptr);
    if (tools && tools->cmd)
        //lst_clear_cmd(&tools->cmd, &free_ptr);
    if (clear /*== 1*/)
    {
        if (tools && tools->pwd)
            free_ptr(tools->pwd);
        if (tools && tools->oldpwd)
            free_ptr(tools->oldpwd);
        if (tools && tools->envp)
            free_str_tab(tools->envp);
        rl_clear_history();
    }
}

void close_file(t_cmd *cmd, int close_backup)
{
    if (cmd->files)
    {
        if (cmd->files->fd_in != -1)
            close(cmd->files->fd_in);
        if (cmd->files->fd_out != -1)
            close(cmd->files->fd_out);
        if (close_backup)
            restore_files(cmd->files);
    }
    close_pipe(cmd, NULL);
}

