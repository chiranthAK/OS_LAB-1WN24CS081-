#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t chopstick[N];
sem_t room;

void think(int i) {
    printf("Philosopher %d is thinking\n", i);
    sleep(1);
}

void eat(int i) {
    printf("Philosopher %d is eating\n", i);
    sleep(1);
}

void* philosopher(void* num) {
    int i = *(int*)num;

    while (1) {
        think(i);

        sem_wait(&room);

        sem_wait(&chopstick[i]);
        sem_wait(&chopstick[(i + 1) % N]);
        eat(i);

        sem_post(&chopstick[i]);
        sem_post(&chopstick[(i + 1) % N]);

        sem_post(&room);
    }
}

int main() {
    pthread_t thread_id[N];
    int phil[N];

    sem_init(&room, 0, 4);
    for (int i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    for (int i = 0; i < N; i++) {
        phil[i] = i;
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}
