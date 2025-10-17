#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <unistd.h>

int main(void)
{
    char *args[] = {"/bin/ls", "-l", NULL};
    execve(args[0], args, NULL);
    return 0; // จะไม่มาถึงตรงนี้ ถ้า execve สำเร็จ
}
