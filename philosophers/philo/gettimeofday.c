#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	struct timeval	start, end;
	long			sec;
	int				usec;

	gettimeofday(&start, NULL);
	sleep(1);
	usleep(1000000);
	gettimeofday(&end, NULL);
	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	printf("%ld %d", sec, usec);
}