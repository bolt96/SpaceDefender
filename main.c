#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h> 
#include <unistd.h>

int alarm_stop = FALSE;
unsigned int alarm_period = 10;
void on_alarm(int signal) {
  if (stop_alarm) return;
  else alarm(alarm_period);
  // Insert periodic stuff here.
}


int main(int agrv, char *argv[])
{
	  signal(SIGALRM, on_alarm);
  alarm(alarm_period);
  for (;;) {
	//file open
	int fd,i;
    char buf[100];
    fd=open(argv[1],O_RDONLY);

	//file write (to screen - see `cat` implementation)
      while((i=read(fd,buf,1))>0)
        {
          printf("%c",buf[0]);
        }
      close(fd);
    
  }
	//start timer
	
	//
	return 0;
}
