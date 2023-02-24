#include "shell.h"
/**
 * builtin_env - prints environment variables
 * Return: Nothing
 */
void builtin_env(void)
{
	char **env = environ;

	while (*env)
	{
		size_t len = _strlen(*env);
		ssize_t w = write(STDOUT_FILENO, *env, len);

		if (w == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		w = write(STDOUT_FILENO, "\n", 1);

		if (w == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}

		env++;
	}
}
