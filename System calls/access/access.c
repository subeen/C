#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char*argv[])
{
int fp;
char* b[20];
int i= access(argv[1],F_OK);
if(i==0)
{
fp=open(argv[1],O_RDONLY);
read(fp,b,20);
printf("%s",b);
}
else
{
fp=open(argv[1],O_WRONLY|O_CREAT);
write(fp,"hello",10);
}
close(fp);
return 0;
}
