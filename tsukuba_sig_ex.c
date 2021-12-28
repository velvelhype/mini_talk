#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int     char_stock = 0;

void    sigint_handler(int signum)
{
	// printf("signum %d\n", signum);
	if(signum == SIGUSR1)
		char_stock += 1;
}

int main()
{
	printf("%d\n", getpid());
	struct sigaction sa_sigint;

	memset(&sa_sigint, 0, sizeof(sa_sigint));
	sa_sigint.sa_handler = sigint_handler;
	sa_sigint.sa_flags = SA_RESTART;

	if (sigaction(SIGUSR1, &sa_sigint, NULL) < 0) {
		perror("sigaction");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa_sigint, NULL) < 0) {
		perror("sigaction");
		exit(1);
	}
	int count  = 0;
	while (1) 
	{
		pause();
		// printf("char_stock: %d\n", char_stock);
		count++;
		if(count != 8)
			char_stock <<= 1;
		else
		{
		    //  printf("sent : %c\n", char_stock);
			 write(1, &char_stock, 1);
		     count = 0;
		     char_stock = 0;
		//      putchar(char_stock);
		}
		// printf("main: return from pause. sigint_count(%d)\n",
		//     sigint_count);
	}
}