#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <string.h>

typedef struct { int values[6]; int count; } Shared;
int main(void) {
    const char *shm="/sensor_shm_demo";
    const char *ready="/sensor_ready_demo";
    shm_unlink(shm); sem_unlink(ready);
    int fd=shm_open(shm,O_CREAT|O_RDWR,0600);
    if(fd<0 || ftruncate(fd,sizeof(Shared))<0) { perror("shm"); return 1; }
    Shared *s=mmap(NULL,sizeof(Shared),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(s==MAP_FAILED) { perror("mmap"); return 1; }
    sem_t *sem=sem_open(ready,O_CREAT,0600,0);
    if(sem==SEM_FAILED) { perror("sem_open"); return 1; }
    pid_t pid=fork();
    if(pid==0) {
        sem_wait(sem);
        int sum=0,max=0;
        for(int i=0;i<s->count;i++) {
            if(i==0 || s->values[i]>max) max=s->values[i];
            sum+=s->values[i];
        }
        printf("shared analyser: %d readings, average %.1f, max %d\n",
               s->count,(double)sum/s->count,max);
        fflush(stdout);
        _exit(0);
    }
    int a[6]={31,33,36,34,41,38};
    memcpy(s->values,a,sizeof(a)); s->count=6;
    sem_post(sem); waitpid(pid,NULL,0);
    sem_close(sem); sem_unlink(ready);
    munmap(s,sizeof(Shared)); close(fd); shm_unlink(shm);
    return 0;
}
