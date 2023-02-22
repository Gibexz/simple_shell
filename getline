#include "main.h"
#define BUFF_SIZE 1024

/**
 * _getline - function to get an input from the terminal through stdin
 * @command: The inputed command and argument as a string
 * @buffsize: buffer size for storing the command
 * @stream: Pointer to stdin
 *
 * Return: n = number of characters read (value to be returned)
 */
ssize_t _getline(char **command, size_t *buffsize, FILE *stream)
{
	char *cmd_buffer = NULL, *temp = NULL;
	int fd;
	size_t n = 0, count;
	static size_t i;

	fd = fileno(stream);/* get the file discriptor for the stream */
	if (fd != 0) /* failed to get file discriptor of 0 i.e. stdin) */
		return (-1);
	cmd_buffer = malloc(BUFF_SIZE);
	if (cmd_buffer == NULL)
		return (-1);
	*buffsize = BUFF_SIZE;
	while (1)
	{
		if (n + BUFF_SIZE >= *buffsize)
		{	/* buffer is full, allocation more memory */
			temp = realloc(cmd_buffer, (*buffsize + BUFF_SIZE));
			if (temp == NULL)
				return (-1);
			cmd_buffer = temp;
			*buffsize += BUFF_SIZE;
		}
		count = read(fd, cmd_buffer, BUFF_SIZE);/* reads from fd which is stdin */
		if (count < 1)
			return (-1); /* read() error */
		else if (count == 0)
			break; /* end of input */
		n += count;/* updates number of character read */
		i += 1;
		if (cmd_buffer[n - 1] == '\n')
		{
			*command = cmd_buffer;
			/*printf("%lu, %lu\n", n, i);*/
			return (n);
		}
	}
	if (n > 0)
		return (n);
	else
		return (-1);
}
