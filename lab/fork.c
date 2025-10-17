#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

//int main(void)
//{
//    printf("Root PID: %d\n", getpid());
//    fork();
//    fork();
//    fork();
//    printf("PID: %d, PPID: %d\n", getpid(), getppid());
//    return 0;
//}

int main()
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
        printf("This is the child process. (pid: %d)\n", getpid());
    else
        printf("This is the parent process. (pid: %d)\n", getpid());

    return (0);
}