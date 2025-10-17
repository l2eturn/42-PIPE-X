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
    pid_t pid = fork();
    if (pid > 0) {
        // parent process
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    } else if (pid == 0) {
        // child process
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    }

}