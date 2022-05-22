/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitArgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:33:50 by bpirzad           #+#    #+#             */
/*   Updated: 2022/05/22 18:38:01 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_error(char	*message, t_cmd	**cmd)
{
	delete_struct((*cmd)->cmd1);
	delete_struct((*cmd)->cmd2);
	delete_struct((*cmd)->mypaths);
	if ((*cmd)->cmd1_path)
		free((*cmd)->cmd1_path);
	if ((*cmd)->cmd2_path)
		free((*cmd)->cmd2_path);
	ft_error(message);
}

char	*doublejoin(char *mypath, char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin(mypath, "/");
	return (ft_strjoin(tmp, cmd));
}

void	ft_init_path1(t_cmd **cmd)
{
	int	i;

	i = 0;
	while ((*cmd)->mypaths[i])
	{
		(*cmd)->cmd1_path = doublejoin((*cmd)->mypaths[i], (*cmd)->cmd1[0]);
		if (!access((*cmd)->cmd1_path, F_OK))
			break ;
		free((*cmd)->cmd1_path);
		(*cmd)->cmd1_path = NULL;
		i++;
	}
}

void	ft_init_path2(t_cmd **cmd)
{
	int	i;

	i = 0;
	while ((*cmd)->mypaths[i])
	{
		(*cmd)->cmd2_path = doublejoin((*cmd)->mypaths[i], (*cmd)->cmd2[0]);
		if (!access((*cmd)->cmd2_path, F_OK))
			break ;
		free((*cmd)->cmd2_path);
		(*cmd)->cmd2_path = NULL;
		i++;
	}
}

void	init_cmd(t_cmd *cmd, char **envp, char **argv)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], ft_strlen("PATH")))
		i++;
	if (envp[i])
		cmd->mypaths = ft_split(envp[i] + 5, ':');
	else
		ft_error("'PATH' doesn't exist");
	cmd->cmd1 = ft_split(argv[2], ' ');
	cmd->cmd2 = ft_split(argv[3], ' ');
	ft_init_path1(&cmd);
	ft_init_path2(&cmd);
	if (!cmd->cmd1_path && !cmd->cmd2_path)
		cmd_error("ERROR: cmd1 and cmd2 doesn't exist", &cmd);
	if (!cmd->cmd1_path)
		cmd_error("ERROR: cmd1 doesn't exist", &cmd);
	if (!cmd->cmd2_path)
		cmd_error("ERROR: cmd2 doesn't exist", &cmd);
}
