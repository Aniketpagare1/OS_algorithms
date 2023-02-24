#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5 // Number of philosophers

int forks[N]; // Array to keep track of which forks are in use

void pick_up_forks(int id)
{
    int left_fork = id;
    int right_fork = (id + 1) % N;

    // Wait until both forks are available
    while (forks[left_fork] || forks[right_fork])
    {
        // Do nothing
    }

    // Pick up the forks
    forks[left_fork] = 1;
    forks[right_fork] = 1;
}

void put_down_forks(int id)
{
    int left_fork = id;
    int right_fork = (id + 1) % N;

    // Put down the forks
    forks[left_fork] = 0;
    forks[right_fork] = 0;
}

void philosopher(int id)
{
    while (1)
    {
        // Think for a random amount of time
        printf("Philosopher %d is thinking\n", id);
        srand(time(NULL));
        int thinking_time = rand() % 5;
        sleep(thinking_time);

        // Pick up the forks
        printf("Philosopher %d is hungry\n", id);
        pick_up_forks(id);

        // Eat for a random amount of time
        printf("Philosopher %d is eating\n", id);
        int eating_time = rand() % 5;
        sleep(eating_time);

        // Put down the forks
        put_down_forks(id);
    }
}

int main()
{
    int i;

    // Initialize forks array
    for (i = 0; i < N; i++)
    {
        forks[i] = 0;
    }

    // Create philosopher processes
    for (i = 0; i < N; i++)
    {
        if (fork() == 0)
        {
            philosopher(i);
            exit(0);
        }
    }

    // Wait for philosopher processes to finish
    for (i = 0; i < N; i++)
    {
        wait(NULL);
    }

    return 0;
}
