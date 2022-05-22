/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:22:31 by bpirzad           #+#    #+#             */
/*   Updated: 2022/05/22 17:24:22 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_cmd
{
	char	**cmd1;
	char	**cmd2;
	char	**mypaths;
	char	*cmd1_path;
	char	*cmd2_path;
}				t_cmd;

typedef struct s_proccess
{
	int		fds[2];
	pid_t	child1;
	pid_t	child2;
}				t_proc;

void	ft_error(char	*message);
void	cmd_error(char	*message, t_cmd	**cmds);
char	*doublejoin(char *mypath, char *cmd);
void	init_cmd(t_cmd *cmd, char **envp, char **argv);
void	pipex(t_cmd *cmd, t_proc *proc, char **argv, char **envp);
void	del(t_cmd	*cmds);
void	ft_check(char	**argv);

#endif