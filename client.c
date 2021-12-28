#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void        decimal_conversion(char ascii, int power, int pid)
{
  if (power > 0)
    decimal_conversion(ascii / 2, power - 1, pid);
  if ((ascii % 2) == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  usleep(1);
}

void        ascii_to_binary(char *str, int pid)
{
  int       i;

  i = 0;
  while (str[i] != '\0')
    {
      decimal_conversion(str[i], 7, pid);
      i += 1;
    }
}