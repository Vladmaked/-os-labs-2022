#include "sys/wait.h"
#include "memory.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
    char *newargv[argc];
    memcpy(newargv, argv + 1, argc * sizeof(char *));
    newargv[argc-1] = NULL;

    int status;
    int pid = fork();
    if (pid == 0) {
        execvp(newargv[0], newargv);
        exit(-1);
    } else {
        waitpid(pid, &status, 0);
        if (status == 0) {
            printf("Success!\n");
        } else {
            printf("Failed, exit code = %d\n",status);
        }
    }
    return 0;
}
