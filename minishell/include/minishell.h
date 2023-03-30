/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <aaduan-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:26:36 by aaduan-b          #+#    #+#             */
/*   Updated: 2023/03/30 11:31:27 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include <stdint.h>
# include <stdio.h>
#include  <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <limits.h>

# include "../libft/libft.h"

# define MSG "minishell$ "

# define ERR_CMD_NOT_FOUND 127
# define ERR_CMD_NOT_EXECUTABLE 126

enum e_success {
    SUCCESS,
    FAILURE
};

enum e_quote {
    DEFAULT,
    SQUOTE,
    DQUOTE
};

enum e_token {
    SPACES = 1,
    WORD,
    VARIABLE,
    PIPE,
    INPUT,
    TRUNC,
    HEREDOC,
    APPEND,
    END
};

typedef struct s_tokens
{
    int type;
    int status;
    char *str;
    char *str_backup;
    int var;
    int join;
    struct s_tokens *prev;
    struct s_tokens *next;
} t_tokens;

typedef struct s_files
{
    int fd_in;
    int fd_out;
    int stdin_backup;
    int stdou_backup;
    char *infile;
    char *outfile;
    int heredoc_quotes;
    char *heredoc_limit;
} t_files;

typedef struct s_cmds
{
    char *cmd;
    char *path;
    char **args;
    int pipe_out;
    int *pipe;
    t_files *files;
    struct s_cmd *next;
    struct s_cmd *prev;
} t_cmd;

typedef struct s_tools
{
    int inter;
    t_tokens *tokens;
    char *u_input;
    char **envp;
    char *pwd;
    char *oldpwd;
    t_cmd *cmd;
    pid_t pid;
} t_tools;

extern int g_exit_code;

//UTILS
void free_ptr(void *ptr);
char *join_str(char *s1, char *s2);
int error_msg(char *cmd, char* plus, char *error_msg, int num);
void print_error(char *error_msg, char *plus);
int tools_init(t_tools *tools, char **env);
void file_init(t_cmd *cmd);
void free_str_tab(char **tab);
void free_files(t_files *files);
void free_tools(t_tools *tools, int clear);
void close_file(t_cmd *cmd, int close_backup);
void exit_shell(t_tools *tools, int exno);
int command_not_found(t_tools *tools, t_cmd *cmd);
int check_if_directory(char *cmd);

//ENVIROMENTAL_VARIABLES
int count_env(char **env);
int check_env_var_name(char *var);
char *env_value(char **env, char *var);
int env_position(char **env, char *var);
int env_set(t_tools *tools, char *key, char *val);
int env_remove(t_tools *tools, int pos);

//BUILTINS
int ft_cd(t_tools *tools, char **args);
int ft_echo(t_tools *tools, char **args);
int ft_env(t_tools *tools, char **args);
int ft_exit(t_tools *tools, char **args);
int ft_export(t_tools *tools, char **args);
int ft_pwd(t_tools *tools, char **args);
int ft_unset(t_tools *tool, char **args);

//REDIRECTIONS
int check_correct(t_files *files);
int redirect_files(t_files *files);
int restore_files(t_files *files);
void close_pipe(t_cmd *cmd, t_cmd *skip_cmd);
int create_pipe(t_tools *tools);
int set_pipe(t_cmd *cmd, t_cmd *c);

//EXECUTION
int execute(t_tools *tools);
int builtins(t_tools *tools, t_cmd *cmd);
int execute_cmd(t_tools *tools, t_cmd *cmd);
char *get_path(t_tools *tools, char *name);

#endif