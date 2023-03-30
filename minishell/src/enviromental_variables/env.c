/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:04:05 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 16:02:37 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int count_env(char **env)
{
    int i;

    i = 0;
    while (env && env[i])
    {
        i++;
    }
    return (i);
}

int check_env_var_name(char *var)
{
    int i;
    
    i = 0;
    if(ft_isalpha(var[i]) == 0 && var[i] != '_')
        return (0);
    i++;
    while (var[i] && var[i] != '=')
    {
        if (ft_isalnum(var[i]) == 0 && var[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

char *env_value(char **env, char *var)
{
    int i;
    char *tmp;

    tmp = ft_strjoin(var, "=");
    if (!tmp)
        return (NULL);
    i = 0;
    while (env[i])
    {
        if (strncmp(tmp, env[i], ft_strlen(tmp)) == 0)
        {
            free_ptr(tmp);
            return (ft_strchr(env[i], '=') + 1);
        }
        i++;
    }
    free_ptr(tmp);
    return (NULL);
}

int env_position(char **env, char *var)
{
    int i;
    char *tmp;

    tmp = ft_strjoin(var, "=");
    if (!tmp)
        return (-1);
    i = 0;
    while (env[i])
    {
        if (strncmp(tmp, env[i], ft_strlen(tmp)) == 0)
        {
            free_ptr(tmp);
            return (i);
        }
        i++;
    }
    free_ptr(tmp);
    return (-1);
}