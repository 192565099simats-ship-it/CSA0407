#include <stdio.h>
#include <pthread.h>
#define THREADS 4
#define FRAMES_PER_THREAD 100000

long total_frames=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void *process_camera(void *arg) {
    long local=0;
    for(int i=0;i<FRAMES_PER_THREAD;i++) local++;
    pthread_mutex_lock(&lock);
    total_frames+=local;
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main(void) {
    pthread_t workers[THREADS];
    for(long i=0;i<THREADS;i++)
        pthread_create(&workers[i],NULL,process_camera,(void*)i);
    for(int i=0;i<THREADS;i++) pthread_join(workers[i],NULL);
    printf("Workers: %d\nProcessed frames: %ld\n",THREADS,total_frames);
    pthread_mutex_destroy(&lock);
    return 0;
}
