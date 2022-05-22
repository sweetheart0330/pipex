/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:34:05 by bpirzad           #+#    #+#             */
/*   Updated: 2022/05/22 18:43:03 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	delete_struct(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	del(t_cmd	*cmds)
{
	delete_struct(cmds->cmd1);
	delete_struct(cmds->cmd2);
	delete_struct(cmds->mypaths);
	free(cmds->cmd1_path);
	free(cmds->cmd2_path);
}

void	child_1(t_cmd	*cmd, char	**envp, char	*filename, t_proc	*proc)
{
	int	infile;

	infile = open(filename, O_RDONLY, 0777);
	if (infile < 0)
		cmd_error("ERROR: Unable to open 'infile'", &cmd);
	if (dup2(infile, STDIN_FILENO) < 0)
		cmd_error("ERROR: Unable to dup infile and STDIN", &cmd);
	if (dup2(proc->fds[1], STDOUT_FILENO) < 0)
		cmd_error("ERROR: Unable to dup fds[1] and STDOUT", &cmd);
	close(proc->fds[0]);
	execve(cmd->cmd1_path, cmd->cmd1, envp);
	close(infile);
	close(proc->fds[1]);
	exit(EXIT_FAILURE);
}

void	child_2(t_cmd	*cmd, char	**envp, char	*filename
, t_proc	*proc)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dup2(proc->fds[0], STDIN_FILENO) < 0)
		cmd_error("ERROR: Unable to dup fds[0] and STDIN", &cmd);
	if (dup2(fd, STDOUT_FILENO) < 0)
		cmd_error("ERROR: Unable to dup outfile and STDOUT", &cmd);
	close (proc->fds[1]);
	execve(cmd->cmd2_path, cmd->cmd2, envp);
	close(fd);
	close(proc->fds[0]);
	exit(EXIT_FAILURE);
}

void	pipex(t_cmd *cmd, t_proc *proc, char **envp, char **argv)
{
	proc->child1 = fork();
	if (proc->child1 < 0)
		cmd_error("ERROR: Forking one failed", &cmd);
	if (!proc->child1)
		child_1(cmd, envp, argv[1], proc);
	proc->child2 = fork();
	if (proc->child2 < 0)
		cmd_error("ERROR: Forking two failed", &cmd);
	if (!proc->child2)
		child_2(cmd, envp, argv[4], proc);
	waitpid(0, NULL, 0);
}
