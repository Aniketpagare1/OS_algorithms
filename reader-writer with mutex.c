// Implement Reader-Writer problem using mutex.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int readcount = 0;
pthread_mutex_t mutex, wrt;

void *reader(void *arg)
{
    int f;
    f = ((int)arg);
    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1)
        pthread_mutex_lock(&wrt);
    pthread_mutex_unlock(&mutex);
    printf("\nData read by the reader%d is %d", f, readcount);
    sleep(1);
    pthread_mutex_lock(&mutex);
    readcount--;
    if (readcount == 0)
        pthread_mutex_unlock(&wrt);
    pthread_mutex_unlock(&mutex);
}

void *writer(void *arg)
{
    int f;
    f = ((int)arg);
    pthread_mutex_lock(&wrt);
    readcount++;
    printf("\nData writen by the writer%d is %d", f, readcount);
    sleep(1);
    readcount--;
    pthread_mutex_unlock(&wrt);
}

int main()
{
    int i, b;
    pthread_t rtid[5], wtid[5];
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&wrt, NULL);
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
}
