#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int cnt = 0;
pthread_mutex_t mutex;


void *count(void *arg)
{
	int i;
	char *name = (char *)arg;
	pthread_mutex_lock(&mutex);
	cnt = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%s cnt: %d\n", name, cnt);
		cnt++;
		usleep(1);
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int main()
{
	pthread_t t1, t2;

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, count, (void *)"thread1") != 0)
	{
		perror("pthread_create");
		exit(1);
	}
	if (pthread_create(&t2, NULL, count, (void *)"thread2") != 0)
	{
		perror("pthread_create");
		exit(1);
	}
	if (pthread_join(t1, NULL) != 0)
	{
		perror("join");
		exit(1);
	}
	if (pthread_join(t2, NULL) != 0)
	{
		perror("join");
		exit(1);
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}