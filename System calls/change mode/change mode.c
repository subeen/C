#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
void change()
{
struct stat a;
int flag=(S_IWGRP|S_IWOTH);
stat("/home/student/xyz.txt",&a);
flag=((a.st_mode&~flag)|S_ISUID);
if(chmod("/home/student/xyz.txt",flag))
perror("chmod");
}
int main()
{
change();
}
