
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/stat.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#include<errno.h>

#include<signal.h>
#include<sys/wait.h>

#include<time.h>
#include<sys/time.h>

#include<stdarg.h>
#include<dirent.h>

void strcpy_fuction(char *str) 
{ 
	char buffer[16]; 
	strcpy(buffer,str); 
	printf("\nbuffer = %s\n",buffer);
}


void main()
{
	char main_buf[25];
	strncpy(main_buf,"aaaaaaaaaaaaaaaaaaaa",sizeof(main_buf));
	printf("\nmain_buf = %s",main_buf);
	strcpy_fuction(main_buf);
}

