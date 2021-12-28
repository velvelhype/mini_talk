#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void trap( int no )   /* BSD 風シグナルハンドラ */
{
     char *mes = "signal get\n";
     write( 1, mes, strlen(mes) );
}

int main( )
{
     char buff[256];
     int ret;
     struct sigaction sa;

     /* sa の内容をとりあえず 0 でクリアしておく */
     memset( &sa, 0, sizeof(struct sigaction) );  
     sa.sa_handler = trap;         /* シグナルハンドラの設定 */
     sa.sa_flags |= SA_RESTART;    /* システムコールが中止しない */ 

     /* ハンドラの設定。ただし古い情報は不要 */
     if( sigaction( SIGINT, &sa, NULL ) != 0 ) {
          fprintf( stderr, "sigaction(2) error!\n" );
          exit( 1 );
     } 

     while( 1 ) {
          printf( "read wait..\n" );
          ret = read( 0, buff, sizeof(buff) );
          write( 1, buff, ret );
     }
}