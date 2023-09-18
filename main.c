#include "shell.h"

/**
 * main - Entry point for the shell program
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    int background;

    /* Register SIGINT handler */
    signal(SIGINT, sigint_handler);

    while (1)
    {
        printf("ComplexShell> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        parse_command(input, args, &background);

        pid_t pid = fork();

        if (pid == -1)
        {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0)
        {
            if (background)
            {
                int dev_null = open("/dev/null", O_RDONLY);
                dup2(dev_null, 0);
                close(dev_null);
            }

            int result = execvp(args[0], args);

            if (result == -1)
            {
                perror("Command execution failed");
                exit(1);
            }

            exit(EXIT_CODE);
        }
        else
        {
            if (!background)
            {
                wait(NULL); /* Wait for the child process to complete */
            }
        }
    }

    return (0);
}
