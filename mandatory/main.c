#include "pipex.h"
void	ft_check(char **argv)
{
	while (*argv[2] && *argv[2] == ' ')
		argv[2]++;
	if (!argv[2])
		ft_error("cmd1 doesn't exist");
	while (*argv[3] && *argv[3] == ' ')
		argv[3]++;
	if (!argv[3])
		ft_error("cmd2 doesn't exist");
}

void	ft_error(char *str)
{
	write(1,str, ft_strlen(str));
	exit(1);
}

int main(int argc, char **argv, char **envp)
{
	t_proc	proc;
	t_cmd	cmd;

	if (argc != 5)
		ft_error("Invalid number of arguments");
	ft_check(argv);
	if (pipe(proc.fds) == -1)
		ft_error("Pipe failed");
	init_cmd(&cmd, envp, argv);
	pipex(&cmd, &proc, envp, argv);
	del(&cmd);
	return (0);
}