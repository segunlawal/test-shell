#include "shell.h"
/**
 * execute_cmd - execute command passed from standard input
 * @argv: argument vector
 * Return: Nothing
 */

void execute_cmd(char **argv)
{
	char **env = environ;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
	}
	else if (pid == 0)
	{
		char *comm = argv[0];
		char *comm_path = get_path(comm);

		if (execve(comm_path, argv, env) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				write(STDOUT_FILENO, "Command exited\n", 15);
			}
		}
		else if (WIFSIGNALED(status))
		{
			write(STDOUT_FILENO, "Command killed\n", 15);

		}
	}
}
