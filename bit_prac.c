      #include <stdio.h>
      #include <signal.h>
	  #include <string.h>
	  #include <stdlib.h>
	  #include <unistd.h>
    
int main()
{
	char a = 'a';
	int avalue = a;
	// for(int i = 10; i > 0 ; i--)
	// 	printf("%d %d\n", i,  a >> i & 1);
	int b = 0;
	b = b << 1;
	b += 1;
	b = b << 1;
	b += 1;
	b = b << 1;
	b = b << 1;
	b = b << 1;
	b = b << 1;
	printf("%d\n", b);
}