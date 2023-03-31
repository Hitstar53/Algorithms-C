#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define PHILOSOPHERS 5
#define MEALS 2

sem_t chopsticks[PHILOSOPHERS];
pthread_t philosophers[PHILOSOPHERS];

void *think_eat_sleep(void *arg)
{
    int id = *((int *)arg);
    int left_chopstick = id;
    int right_chopstick = (id+1)%PHILOSOPHERS;
    int meals_eaten = 0;
    while (meals_eaten<MEALS)
    {
        printf("%d\tthinking\n", id);
        usleep(rand()%50000); //thinking time
        sem_wait(&chopsticks[left_chopstick]);
        sem_wait(&chopsticks[right_chopstick]); // wait for chopsticks
        printf("%d\tstarts eating\n", id);
        usleep(rand() % 50000); //eating time
        printf("%d\tends eating\n", id);
        meals_eaten++;
        sem_post(&chopsticks[left_chopstick]);
        sem_post(&chopsticks[right_chopstick]);
        usleep(rand() % 50000); // sleeping
    }
    printf("%d\tdone with meals\n", id);
    return NULL;
}
int main()
{
    srand(time(NULL));
    for (int i=0;i<PHILOSOPHERS;i++)
    {
        sem_init(&chopsticks[i],0,1);
    }
    int ids[PHILOSOPHERS];
    printf("Ph_id\tStatus\n");
    for (int i=0;i<PHILOSOPHERS;i++)
    {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, think_eat_sleep, &ids[i]);
    }
    for (int i=0;i<PHILOSOPHERS;i++)
    {
        pthread_join(philosophers[i],NULL);
    }
    for (int i=0;i<PHILOSOPHERS;i++)
    {
        sem_destroy(&chopsticks[i]);
    }
    return 0;
}