/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:46:14 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 23:30:14 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char **env_realloc(t_tools *tools, int size)
{
    char **ret;
    int i;

    ret = ft_calloc(size + 1, sizeof *ret);
    if (!ret)
        return (NULL);
    i = 0;
    while (tools->envp[i] && i < size)
    {
        ret[i] = ft_strdup(tools->envp[i]);
        free_ptr(tools->envp[i]);
        i++;
    }
    free(tools->envp);
    return (ret);
}

int env_remove(t_tools *tools, int pos)
{
    int i;
    int count;

    if (pos > count_env(tools->envp))
        return (0);
    free_ptr(tools->envp[pos]);
    i = pos;
    count = pos;
    while (tools->envp[i + 1])
    {
        tools->envp[i] = ft_strdup(tools->envp[i + 1]);
        free_ptr(tools->envp[i + 1]);
        count++;
        i++;
    }
    tools->envp = env_realloc(tools, count);
    if (!tools->envp)
        return (0);
    return (1);
}

int env_set(t_tools *tools, char *key, char *val)
{
    int pos;
    char *tmp;

    pos = env_position(tools->envp, key);
    if (val == NULL)
        val = "";
    tmp = ft_strjoin("=", val);
    if (!tmp)
        return (0);
    if (pos != -1 && tools->envp[pos])
    {
        free_ptr(tools->envp[pos]);
        tools->envp[pos] = ft_strjoin(key, tmp);
    }
    else
    {
        pos = count_env(tools->envp);
        tools->envp = env_realloc(tools, pos + 1);
        if (!tools->envp)
            return (0);
        tools->envp[pos] = ft_strjoin(key, tmp);
    }
    free_ptr(tmp);
    return (1);
}