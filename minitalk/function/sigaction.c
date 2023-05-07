#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sigint_handler(int signo, siginfo_t *info, void *p)
{
	printf("ctrl-c를 눌렀습니다.\n");
}

int	main(void)
{
	struct sigaction	act;
	struct sigaction	oldact;

	act.sa_sigaction = sigint_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act, NULL);
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", i);
		sleep(1);
		++i;
	}
}
