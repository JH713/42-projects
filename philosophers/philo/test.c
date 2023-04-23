#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void	sleep_func(int time_ms)
{
	struct timeval	start;
	struct timeval	now;
	struct timeval	target;
	
	gettimeofday(&start, NULL);
	target.tv_usec = start.tv_usec + (time_ms % 1000) * 1000;
	target.tv_sec = start.tv_sec + time_ms / 1000 + target.tv_usec / 1000000;
	target.tv_usec %= 1000000;
	gettimeofday(&now, NULL);
	while (now.tv_sec < target.tv_sec || now.tv_usec < target.tv_usec)
	{
		gettimeofday(&now, NULL);
		usleep(10);
	}
	return ;
}

int main(void)
{
	struct timeval	start, end;
	long			sec;
	int				usec;
	long long		time;

	gettimeofday(&start, NULL);
	sleep_func(200);
	gettimeofday(&end, NULL);
	time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	printf("%lldms", time);
}