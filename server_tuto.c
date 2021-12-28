#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void        sighandler(int signum)
{
  static int    ascii = 0;
  static int    power = 0;

  if (signum == SIGUSR1)
    ascii += 1 << (7 - power);
  if ((power += 1) == 8)
    {
      putchar(ascii);
      power = 0;
      ascii = 0;
    }
}

int     main(void)
{
  signal(SIGUSR1, sighandler);
  signal(SIGUSR2, sighandler);
  while (42);
  return (0);
}