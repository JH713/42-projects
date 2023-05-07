#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sigint_handler(int signo)
{
	printf("ctrl-c를 눌렀습니다.\n");
}

int main(void)
{
	int i = 0;
	signal(SIGINT, sigint_handler);
	while(i < 10){
		printf("%d\n", i);
		i++;
		sleep(1);
	}
	return 0;
}
