#include "main.h"
char *nullremover(char *buff, ssize_t input)
{
	char *buffer;
	ssize_t i;

	buffer = malloc(sizeof(char) * (input - 1));

	for (i = 0; i < (input - 1); i++)
	{
		buffer[i] = buff[i];
	}
	return (buffer);
}

/**
 *
 *
 *
 */
int main(int argc, char **argv)
{
	int status;
	/* for wait system call of the parent process */
	char *buff, *buffer_1;
	size_t buffsize = 0;
	pid_t process;
	char *arg[] = {NULL};
	ssize_t input;

	buff = malloc(sizeof(char) * buffsize);
	if(buff == NULL)
	{
		perror("Error:");
		return 1
	}

	do {
		if (isatty(0) == 1)
			printf("$ ");

		
		input = getline(&buff, &buffsize, stdin);
		if (input == -1)
		{
			perror("Error:");
			return (1);
			free(buff);
		}

		buffer_1 = nullremover(buff, input);
		process = fork();

		if(process < 0) /* if any error */
		{
			perror("Error:");
			return (1);
		}
		if(process == 0) /* if child process */
		{
			printf("%s", buffer_1);
			if (execve(buffer_1, arg, environ) == -1)
			{
				perror("Error:");
				return (0);
			}
		}
		else /* if parent process */
		{
			wait(&status);
			printf("Parent\n");
		}
	}while(true);
	return (0);
}
