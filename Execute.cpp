#include "Execute.h"

int Execute::run(char *file_name, char *arg[])
{
    int status = 0;
    pid_t child_pid;

    if((child_pid = fork()) < 0)
    {
        perror("fork()");
        return -1;
    }
    else if(0 == child_pid)     /* 子进程 */
    {
        if(-1 == execvp(file_name, arg))
        {
            perror("execvp error");
            return -1;
        }
    }
    else    /* 父进程 */
    {
        if(child_pid != wait(&status))
        {
            perror("Wait error");
            return -1;
        }
        printf("wait ok: %d\n", WEXITSTATUS(status));
    }
    return WEXITSTATUS(status);
}