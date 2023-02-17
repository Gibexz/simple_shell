#include "main.h"

/**
 * tokens_array - function to split the command input into its arguments
 * @cmd_input: pointer to imputed command from terminal
 * @word_Count: Pointer to store the number of arguments pass
 *
 * Return: pointer splited argugment array
 */
char **tokens_array(char *cmd_input, int *word_Count)
{
	char *cmd_Tokens;
	char **temp_args;
	int i;

	temp_args = malloc(strlen(cmd_input) * sizeof(char *));
	if (temp_args == NULL)
	{
		perror("malloc:");
		exit(1);
	}
	cmd_Tokens = strtok(cmd_input, " \n");

	i = 0;
	while (cmd_Tokens != NULL)
	{
		temp_args[i] = malloc(sizeof(char) * strlen(cmd_Tokens) + 1);
		if (temp_args[i] == NULL)
		{
			perror("malloc:");
			exit(1);
}

		strcpy(temp_args[i], cmd_Tokens);
		i++;
		cmd_Tokens = strtok(NULL, " \n");
	}

	*word_Count = i;
	return (temp_args);
}
