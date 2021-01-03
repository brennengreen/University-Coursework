#define _GNU_SOURCE
/* $begin shellmain */
#include "csapp.h"
#define MAXARGS   128

char prompt[] = "uksh";
char cwd[PATH_MAX];

typedef struct {
    pid_t id;
    char name[MAXLINE];
} process; // type to define a process with a pid and name
int num_processes = 0; // number of active processes
process p_list[1000]; // list of processes
pid_t current_fg_process = -1; // current foreground process, -1 = no fg process

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv); 
void sigint_handler(int sig_num);
void sigchld_handler(int sig_num);
void display_plist();
void add_to_plist(pid_t pid, char name[MAXLINE]);
void remove_from_plist(pid_t pid);

int main() 
{
    signal(SIGCHLD, sigchld_handler); // Set up SIGCHLD handler
    signal(SIGINT, sigint_handler); // Set up SIGINT handler
    char cmdline[MAXLINE]; /* Command line */

    while (1) {
        /* Read */
        printf("%s (%s) > ", prompt, getcwd(cwd, sizeof(cwd)));                   
        Fgets(cmdline, MAXLINE, stdin); 
        if (feof(stdin)) {
            exit(0);
        }


        /* Evaluate */
        eval(cmdline);
    } 
}
/* $end shellmain */

/* sigint_handler */
/* intercept sigint signal */
void sigint_handler(int sig_num) {
    if (current_fg_process != -1) { // if there is a foreground process, terminate it
        kill(current_fg_process, SIGINT);
        current_fg_process = -1;
    } else { // if no foreground process, tell the user
        printf("No foreground process!\n");
        printf("%s (%s) > ", prompt, getcwd(cwd, sizeof(cwd)));                   
    }
    fflush(stdout);
}

/* sigchld_handler */
/* if a child process is terminated, check if its in the p_list and remove if it is */
void sigchld_handler(int sig_num) {
    int status;
    pid_t pid = wait(&status);
    if (pid != -1) // if no error
        remove_from_plist(pid);
}

/* display_plist */
/* display the current processes */
void display_plist() {
    printf("---------------------------\n");
    printf("-      PROCESS LIST       -\n");
    printf("--- PID ----------  NAME  -\n");
    for (int i = 0; i < num_processes; i++)
        printf("%d %s", p_list[i].id, p_list[i].name);
}


/* remove_from_plist */
/* find a given process id in the p_list and remove it from the p_list */
void remove_from_plist(pid_t pid) {
    for (int i = 0; i < num_processes; i++) {
        if (p_list[i].id == pid) {
            for (int j = i; j < num_processes; j++) {
                p_list[j] = p_list[j+1]; // shift array
            }
            num_processes--;
            break;
        }
    }
}

/* add_to_plist */
/* add a given pid and name to the p_list as a process */
void add_to_plist(pid_t pid, char name[MAXLINE]) {
    process new_process;    
    new_process.id = pid;
    strcpy(new_process.name, name);
    p_list[num_processes++] = new_process;
    // int status;
    // if (pid = waitpid(pid, &status, 0))
    //     remove_from_plist(pid);
}

/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline) 
{
    char *argv[MAXARGS]; /* Argument list execvpe() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */
    
    strcpy(buf, cmdline);
    bg = parseline(buf, argv); 
    if (argv[0] == NULL)  
	    return;   /* Ignore empty lines */

    if (!builtin_command(argv)) { 
        if ((pid = Fork()) == 0) {   /* Child runs user job */
            if (execvpe(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }
        
	/* Parent waits for foreground job to terminate */
        if (!bg) {
            current_fg_process = pid;
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: waitpid error");
        }
        else {
            printf("%d %s", pid, cmdline);
            add_to_plist(pid, cmdline);
        }
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv) 
{
    if (!strcmp(argv[0], "quit")) /* quit command */
	    exit(0);
    else if (!strcmp(argv[0], "setprompt"))
        strcpy(prompt, argv[1]);
    else if (!strcmp(argv[0], "cd"))
        chdir(argv[1]);
    else if (!strcmp(argv[0], "plist"))
        display_plist();
    else if (!strcmp(argv[0], "&"))    /* Ignore singleton & */
        return 1;
    else return 0;                     /* Not a builtin command */
    return 1;
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) 
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */
    char *comment;

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
        if (*buf && (*buf == '%')) // Ignore the remainder of line if there is a comment
            break;
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