#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char *readline(char *prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char *unused) {}

#elif (defined(__APPLE__) && defined(__MACH__)) || defined(__gnu_linux__)
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char const *argv[])
{
    puts("Lispy Version 0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while (1) {
        char* input = readline("lispy> ");
        add_history(input);

        printf("No you're a %s\n", input);
        free(input);
    }
    
    return 0;
}
