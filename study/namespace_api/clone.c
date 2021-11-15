#define _GNU_SOURCE
#include <sched.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int spawn_bash(void)
{
    char *newargv[] = { "/bin/bash", NULL };

    execv("/bin/bash", newargv);
    perror("exec");
    exit(EXIT_FAILURE);
}

int		child_main(void *args) {
	printf("pid as seen in the child: %lu\n", (unsigned long)getpid());
    spawn_bash();
}

int		main(void) {
	int	namespaces = CLONE_NEWPID  |
					 CLONE_NEWIPC  |
					 CLONE_NEWNET  |
					 CLONE_NEWNS   |
					 CLONE_NEWUSER |
					 CLONE_NEWUTS;
	pid_t child_pid = clone(child_main, malloc(4096) + 4096, SIGCHLD | namespaces, NULL);
	if (child_pid == -1) {
        perror("clone");
        exit(1);
    }
    printf("child pid: %d\n", child_pid);
    waitpid(child_pid, NULL, 0);
    return 0;
}