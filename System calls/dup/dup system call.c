#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<grp.h>
#include<pwd.h>
#include<sys/stat.h>
int main()
{
char *buf1,*buf2="hello";
int fd1,fd2,fd3,fd4;
fd1=open("xyz.txt",O_RDONLY);
fd2=open("abc.txt",O_WRONLY);
close(0);
close(1);
fd3=dup2(fd1,STDIN_FILENO);
fd4=dup2(fd2,STDOUT_FILENO);
printf("%d%d%d%d",fd1,fd2,fd3,fd4);
}
