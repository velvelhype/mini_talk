#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	send_char(int pid, char a)
{
	printf("c: send %c\n", a);
	int i = 7;
	while(i >= 0)
	{
		if (a >> i & 1)
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);	
		usleep(100);
		i--;
	}
}

void	send_str(char **argv)
{
	printf("s: send %s\n", argv[2]);
	
	while(*argv[2])
	{
		send_char(atoi(argv[1]), *argv[2]);
		++(argv[2]);
	}
}

int main(int argc, char **argv)
{
	if(argc != 3)
		exit(1);
	send_str(argv);
}