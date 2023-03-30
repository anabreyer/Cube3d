/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:08:06 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/25 18:46:32 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static int change_directory_error()
// {
//     if (errno == ESTALE)
//         errno = ENOENT;
//     error_msg("cd", strerror(errno), errno);
//     return (0);
// }

static void update_pwd(t_tools *tools, char *pwd)
{
    env_set(tools, "OLDPWD", env_value(tools->envp, "PWD"));
    env_set(tools, "PWD", pwd);
    if (tools->oldpwd)
    {
        free_ptr(tools->oldpwd);
        tools->oldpwd = ft_strdup(tools->pwd);
    }
    if (tools->pwd)
    {
        free_ptr(tools->pwd);
        tools->pwd = ft_strdup(pwd);
    }
    free_ptr(pwd);
}

static int change_directory(t_tools *tools, char *path)
{
    char *ret;
    char *tmp;
    char cwd[PATH_MAX];

    ret = NULL;
    if (chdir(path) != 0)
        return (0);
    ret = getcwd(cwd, PATH_MAX);
    if (!ret)
    {
        error_msg("cd: error retrieving current directpry", "getcwd: cannot access parent directory", strerror(errno), errno);
        ret = ft_strjoin(tools->pwd,  "/");
        tmp = ret;
        ret = ft_strjoin(tmp, path);
        free_ptr(tmp);
    }
    else 
        ret = ft_strdup(cwd);
    update_pwd(tools, ret);
    return (1);
}

int ft_cd(t_tools *tools, char **args)
{
    char *path;

    if (!args || !args[1] || ft_isspace(args[1][0]) || args[1][0] == '\0' || ft_strncmp(args[1], "--", 3) == 0)
    {
        path = env_value(tools->envp, "HOME");
        if (!path || *path == '\0'|| ft_isspace(*path))
            return (!change_directory(tools, path));
    }
    if (args[2])
        return(error_msg("cd", NULL, "too many arguments", EXIT_FAILURE));
    if (ft_strncmp(args[1], "-", 2) == 0)
    {
        path = env_value(tools->envp, "OLDPWD");
        if (!path)
            return (error_msg("cd", NULL, "OLDPWD mot set", EXIT_FAILURE));
        return (!change_directory(tools, path));
    }
    return (!change_directory(tools, args[1]));
}
