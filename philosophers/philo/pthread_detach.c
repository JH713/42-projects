#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	*thread(void *arg)
{
	int num = *(int *)arg;
	printf("Thread start\n");
	sleep(5);
	printf("Thread end\n");
}

int main(void)
{
	pthread_t thid;
	void *ret;
	int a = 100;
	printf("Before Thread\n");
	if (pthread_create(&thid, NULL, thread, (void *)&a) != 0)
	{
		perror("pthread_create() error");
		exit(1);
	}
	pthread_detach(thid);
	pause();
}