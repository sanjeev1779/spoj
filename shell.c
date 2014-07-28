#include  <stdio.h>
#include  <sys/types.h>

void parse(char *input, char **argv)
{
    while (*input != '\0') {
         while (*input == ' ' || *input == '\t' || *input == '\n')
              *input++ = '\0';
         *argv++ = input;
         while (*input != '\0' && *input != ' ' &&
                *input != '\t' && *input != '\n')
              input++;
    }
    *argv = '\0';
}

void execute(char **argv)
{
    pid_t  pid;
    int    status;

    if ((pid = fork()) < 0)
{
         printf("forking child process failed\n");
         exit(1);
    }
    else if (pid == 0)
{
printf("%s\n",argv[0]);
         if (execvp(*argv, argv) < 0)
 {
              printf("* ERROR: Command not found\n");
              exit(1);
         }
    }
    else {
         while (wait(&status) != pid);
    }
}

main()
{
    char  input[1024];
    char  *argv[64];

    while (1)
{
         printf("<> ");
         gets(input);
         printf("\n");
         parse(input, argv);
         if (strcmp(argv[0], "off") == 0)
              return 0;
         execute(argv);
    }
return 0;
}
