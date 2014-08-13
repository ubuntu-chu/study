#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;

void *thread_1(void *arg)
{
    int i = 0;
    pthread_mutex_lock(&mutex_a);
	sleep(1);
    pthread_mutex_lock(&mutex_b);

    for (i = 0; i < 15; i++) {
	printf("thread_1 output : %d\n", i);
	usleep(100);
    }

    pthread_mutex_unlock(&mutex_b);
    pthread_mutex_unlock(&mutex_a);
}

void *thread_2(void *arg)
{
    int i = 0;
    pthread_mutex_lock(&mutex_b);
	sleep(1);
    pthread_mutex_lock(&mutex_a);

    for (i = 0; i < 15; i++) {
	printf("thread_2 output : %d\n", i);
	usleep(100);
    }

    pthread_mutex_unlock(&mutex_a);
    pthread_mutex_unlock(&mutex_b);
}

int main(int argc, char **argv)
{
    pthread_t id1;
    pthread_t id2;
    pthread_mutex_init(&mutex_a, NULL);
    pthread_mutex_init(&mutex_b, NULL);

    pthread_create(&id1, NULL, thread_1, NULL);
    pthread_create(&id2, NULL, thread_2, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_mutex_destroy(&mutex_a);
    pthread_mutex_destroy(&mutex_b);

    return 1;
}
