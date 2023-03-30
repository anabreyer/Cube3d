/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:33:11 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 18:28:50 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char *join_str(char *s1, char *s2)
{
    char *tmp;

    if(!s2)
        return (s1);
    if (!s1)
        return (ft_strdup(s2));
    tmp = s1;
    s1 = ft_strjoin(tmp, s2);
    free_ptr(tmp);
    return (s1);
}

int error_msg(char *cmd, char *plus, char *error_msg, int num)
{
    char *msg;

    msg = ft_strdup("minishell: ");
    if (cmd != NULL)
    {
        msg = join_str(msg, cmd);
        msg = join_str(msg, ": ");
    }
    if (plus != NULL)
    {
        msg = join_str(msg, plus);
        msg = join_str(msg, ": ");
    }
    msg = join_str(msg, error_msg);
    ft_putendl_fd(msg, STDERR_FILENO);
    free_ptr(msg);
    return (num);
}

void print_error(char *error_msg, char *plus)
{
    char *msg;

    msg = ft_strdup("minishell: ");
    msg = join_str(msg, ": ");
	msg = join_str(msg, plus);
    msg = join_str(msg, error_msg);
    ft_putendl_fd(msg, STDERR_FILENO);
    free_ptr(msg);
}
