#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        printf("Child: PID=%d, PPID=%d\n", getpid(), getppid());
        _exit(0);
    } else {
        printf("Parent: PID=%d, child PID=%d\n", getpid(), pid);
        waitpid(pid, NULL, 0);
        printf("Parent: child completed\n");
    }
    return 0;
}
