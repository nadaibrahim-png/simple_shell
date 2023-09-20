#include "main.h"

void execute_commands(char *command)
{
	pid_t pid = fork();
	if (pid < 0)
	{
	perror("execution failed");
	exit(EXIT_FAILURE);
    }
	else if (pid == 0) {
        // Child process
	if (execlp(command, command, NULL) == -1)
	{
	 write(STDERR_FILENO, "Command not found\n", 18);
	exit(EXIT_FAILURE);
	}
    } else {
// Parent process
	int status;
	waitpid(pid, &status, 0);
	}
}

int main()
	{
	char command[MAX_COMMAND_LENGTH];

	while (1) {
        // Display prompt and wait for user input
	write(STDOUT_FILENO, "CISFUN$", 7);
	ssize_t content = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
	if (content == -1) {
	perror("read error");
	exit(EXIT_FAILURE);
	}
	else if (content == 0) {
            // End of file (Ctrl+D) encountered
	break;
	} else {
            // Remove the newline character
	command[strcspn(command, "\n")] = '\0';

            // Execute the command
	execute_commands(command);
	}
	}

return 0;
}
