#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv[]){
	int accmoda,val;
	if(argc!=2)
		err_quit("usage:a.out <descriptor#>");
	if((val = fcnt1(atoi(argv[1]),F_GETFL,0)) < 0)
		err_sys("fcnt1 error for fd %d",atoi(argv[1]));
	accmode = val & O_ACCMODE;
	if(accmode == O_RDONLY)
		printf("read only");
	else if(accmode == O_WRONLY)
		printf("write only");
	else if(accmode == O_RDWR)
		printf("read write");
	else
		err_dump("unknown access mode");
	if(val & O_APPEND)
		printf(",append");
	if(val & O_NONBLOCK)
		printf(",nonblocking");
#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
	if(val & O_SYNC)
		printf(",synchronous writes");
#endif
	putchar('\n');
	exit(0);
}
