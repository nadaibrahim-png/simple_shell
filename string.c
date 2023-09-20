#include "main.h"
void tokenize_command(char *command, char **arguments)
{
	char *token;
	int i = 0;
	token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGUMENTS - 1) {
	arguments[i++] = token;
	token = strtok(NULL, " ");
	}
	 arguments[i] = NULL;
}
