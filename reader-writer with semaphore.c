// Implement Reader Writer problem using semaphore.
// Reader Writer problem is a classic problem in synchronization.
// In this problem, there are multiple readers and multiple writers.
// Readers can read the data at the same time.
// Writers can write the data at the same time.
// But, readers and writers cannot read and write at the same time.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int readcount = 0;
sem_t mutex, wrt;

void *reader(void *arg)
{
    int f;
    f = ((int)arg);
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("\nData read by the reader%d is %d", f, readcount);
    sleep(1);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}

void *writer(void *arg)
{
    int f;
    f = ((int)arg);
    sem_wait(&wrt);
    readcount++;
    printf("\nData writen by the writer%d is %d", f, readcount);
    sleep(1);
    readcount--;
    sem_post(&wrt);
}

int main()
{
    int i, b;
    pthread_t rtid[5], wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    for (i = 0; i <= 2; i++)
    {
        pthread_create(&wtid[i], NULL, writer, (void *)i);
        pthread_create(&rtid[i], NULL, reader, (void *)i);
    }
    for (i = 0; i <= 2; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
    return 0;
}
