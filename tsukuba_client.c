#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	send_char(int pid, char a)
{
	printf("c: send %c\n", a);
	printf("c: send %d\n", a);
	int i = 7;
	while(i >= 0)
	{
		printf("%d\n", a >> i & 1);
		if (a >> i & 1)
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);	
		usleep(100);
		// sleep(1);
		i--;
	}
}

void	send_str(char **argv)
{
	// send_str by char
	printf("s: send %s\n", argv[2]);
	
	while(*argv[2])
	{
		send_char(atoi(argv[1]), *argv[2]);
		++(argv[2]);
	}
}

int main(int argc, char **argv)
{
	send_str(argv);
}