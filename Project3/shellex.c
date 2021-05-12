/* $begin shellmain */
#include "csapp.h"
#define MAXARGS   128
//#define SIGINT 2
/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

void handle_sigint(int sig){
    printf("%d\n", sig);
}
void exit_shell();
int pid_shell();
int ppid_shell();
int help_shell();

int main(int argc, char** argv)
{
    char cmdline[MAXLINE]; /* Command line */

    signal(SIGINT, handle_sigint);
    while (1) {
	/* Read */
	if(argc > 1){
	    printf("%s> ", argv[2]);
	} else {
	    printf("my257sh> ");
	}
	//printf("> ");
	Fgets(cmdline, MAXLINE, stdin);
	if (feof(stdin))
	    exit(0);

	/* Evaluate */
	eval(cmdline);
    }
}
/* $end shellmain */

/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline)
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
	return;   /* Ignore empty lines */

    if (!builtin_command(argv)) {
        if ((pid = Fork()) == 0) {   /* Child runs user job */
            if (execvp(argv[0], argv) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

	/* Parent waits for foreground job to terminate */
	if (!bg) {
	    int status;
	    if (waitpid(pid, &status, 0) < 0)
		unix_error("waitfg: waitpid error");
	}
	else
	    printf("%d %s", pid, cmdline);
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "exit")) /* quit command */
	    exit_shell();
    if (!strcmp(argv[0], "pid")) {   /* Ignore singleton & */
	    printf("%d\n", pid_shell());
	    return 1;
	}
	if (!strcmp(argv[0], "ppid")) {
	    printf("%d\n", ppid_shell());
	    return 1;
	}
	if (!strcmp(argv[0], "help")) {
	    if (sizeof(argv) > 1) {
	        return help_shell(argv[2]);
	    }
	    else {
	        return help_shell("my257sh");
	    }
    	//return 1;
    }
    return 0;                     /* Not a builtin command */
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv)
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */

    buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
	buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
	argv[argc++] = buf;
	*delim = '\0';
	buf = delim + 1;
	while (*buf && (*buf == ' ')) /* Ignore spaces */
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)  /* Ignore blank line */
	return 1;

    /* Should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0)
	argv[--argc] = NULL;

    return bg;
}
/* $end parseline */

void exit_shell()
{
    raise(SIGTERM);
}

int pid_shell()
{
    int p = getpid();
    return p;
}

int ppid_shell()
{
    int p = getppid();
    return p;
}

int help_shell(char* name)
{
    printf("%s\n", name);
    return 1;
}
int cd_shell();
int help_shell();

