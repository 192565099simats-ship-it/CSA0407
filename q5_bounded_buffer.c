#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5
#define ITEMS 20
int buffer[SIZE],in=0,out=0;
sem_t empty_slots,full_slots;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    for(int i=1;i<=ITEMS;i++) {
        sem_wait(&empty_slots);
        pthread_mutex_lock(&lock);
        buffer[in]=i; in=(in+1)%SIZE;
        pthread_mutex_unlock(&lock);
        sem_post(&full_slots);
    }
    return NULL;
}
void *consumer(void *arg) {
    long sum=0;
    for(int i=1;i<=ITEMS;i++) {
        sem_wait(&full_slots);
        pthread_mutex_lock(&lock);
        int item=buffer[out]; out=(out+1)%SIZE;
        pthread_mutex_unlock(&lock);
        sum+=item; sem_post(&empty_slots);
    }
    printf("consumer sum=%ld (expected %d)\n",sum,ITEMS*(ITEMS+1)/2);
    return NULL;
}
int main(void) {
    pthread_t p,c;
    sem_init(&empty_slots,0,SIZE); sem_init(&full_slots,0,0);
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL); pthread_join(c,NULL);
    sem_destroy(&empty_slots); sem_destroy(&full_slots);
    pthread_mutex_destroy(&lock);
    return 0;
}
