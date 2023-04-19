#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_arg{
	int	id;
	struct timeval start;
	int	eat_ms;
	int	sleep_ms;
	pthread_mutex_t mutex;
} t_arg;

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			is_positive;

	result = 0;
	is_positive = 1;
	while (ft_isblank(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_positive = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * is_positive);
}


void *routine(void *arg)
{
	t_arg *time = arg;
	struct timeval start = time->start;
	struct timeval now; 
	int id = time->id;
	int eat_ms = time->eat_ms;
	int sleep_ms = time->sleep_ms;
	pthread_mutex_lock(&(time->mutex));
	gettimeofday(&now, NULL);
	printf("%dms %d is eating\n", (now.tv_usec - start.tv_usec) / 1000, id);
	usleep(eat_ms * 1000);
	gettimeofday(&now, NULL);
	printf("%dms %d is sleeping\n", (now.tv_usec - start.tv_usec) / 1000, id);
	usleep(sleep_ms * 1000);
	gettimeofday(&now, NULL);
	printf("%dms %d is thinking\n", (now.tv_usec - start.tv_usec) / 1000, id);
	usleep(10 * 1000);
	pthread_mutex_unlock(&(time->mutex));
	return ((void *)"finished!");
}

int main(int ac, char *av[])
{
	pthread_t 	philo[2];
	pthread_mutex_t mutex;
	char		*ret[2];
	int			eat_ms, sleep_ms;
	t_arg		arg[2];
	int i;
	struct timeval	start;
	
	gettimeofday(&start, NULL);
	eat_ms = ft_atoi(av[3]);
	sleep_ms = ft_atoi(av[4]);
	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 2)
	{
		arg[i].id = i + 1;
		arg[i].eat_ms = eat_ms;
		arg[i].sleep_ms = sleep_ms;
		arg[i].start = start;
		arg[i].mutex = mutex;
		++i;
	}
	i = 0;
	while (i < 2)
	{
		if (pthread_create(&philo[i], NULL, routine, &arg[i]) != 0)
		{
			perror("pthread_create");
			exit(1);
		}
		++i;
	}
	i = 0;
	while (i < 2)
	{
		if (pthread_join(philo[i], (void **)&ret[i]) != 0)
		{
			perror("pthread_join");
			exit(1);
		}
		++i;
	}
	pthread_mutex_destroy(&mutex);
	printf("%s\n", (char *)ret[0]);
	printf("%s\n", (char *)ret[1]);
}
