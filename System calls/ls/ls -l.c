#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<grp.h>
#include<pwd.h>
#include<sys/stat.h>
#include<time.h>
void printgid(int st_uid,int st_gid)
{
struct group *gp;
struct passwd *pwd;
gp=getgrgid(st_gid);
pwd=getpwuid(st_uid);
if(pwd->pw_name)
printf("%s ",pwd->pw_name);
else
printf("%d ",st_uid);
if(gp->gr_name)
printf("%s ",gp->gr_name);
else
printf("%d ",st_gid);
}


int main(int argc,char*argv[])
{
struct stat a;
int i,j,k,b;
k=lstat(argv[1],&a);
b=a.st_mode&S_IFMT;
switch(b)
{
case S_IFREG:printf("\n-");
break;
case S_IFDIR:printf("\nd");
break;
case S_IFBLK:printf("\nb");
break;
case S_IFCHR:printf("\nc");
break;
case S_IFIFO:printf("\nf");
break;
case S_IFLNK:printf("\nl");
break;
}
for(i=1,j=1<<8;i<10;i++,j>>=1)
{
if(!(i%3==0))
{
switch(i)
{
case 1:
if(a.st_mode&j)
printf("r");
else
printf("-");
break;
case 2:
if(a.st_mode&j)
printf("w");
else
printf("-");
break;
case 4:
if(a.st_mode&j)
printf("r");
else
printf("-");
break;
case 5:
if(a.st_mode&j)
printf("w");
else
printf("-");
break;
case 7:
if(a.st_mode&j)
printf("r");
else
printf("-");
break;
case 8:
if(a.st_mode&j)
printf("w");
else
printf("-");
break;
}
}
else if(i==3)
{
if((a.st_mode&j)&&(a.st_mode&S_ISUID))
printf("s");
else if(a.st_mode&j)
printf("x");
else if(a.st_mode&S_ISUID)
printf("S");
else
printf("-");
}
else if(i==6)
{
if((a.st_mode&j)&&(a.st_mode&S_ISGID))
printf("g");
else if(a.st_mode&j)
printf("x");
else if(a.st_mode&S_ISGID)
printf("G");
else
printf("-");
}
else if(i==9)
{
if((a.st_mode&j)&&(a.st_mode&S_ISVTX))
printf("s ");
else if(a.st_mode&j)
printf("x ");
else if(a.st_mode&S_ISVTX)
printf("S ");
else
printf("- ");
}
}
printf("%d ",a.st_nlink);
printgid(a.st_uid,a.st_gid);
if((b==S_IFBLK)||(b==S_IFCHR))
{
printf("%d ",a.st_rdev>>8);
printf("%d ",a.st_rdev&0x00FF);
}
else
{
printf("%d ",a.st_size);
printf("%s ",ctime(&a.st_mtime));
printf("%s\n",argv[1]);
return 0;
}
}

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<grp.h>
#include<pwd.h>
#include<sys/stat.h>
#include<time.h>
void printgid(int st_uid,int st_gid)
{
struct group *gp;
struct passwd *pwd;
gp=getgrgid(st_gid);
pwd=getpwuid(st_uid);
if(pwd->pw_name)
printf("%s ",pwd->pw_name);
else
printf("%d ",st_uid);
if(gp->gr_name)
printf("%s ",gp->gr_name);
else
printf("%d ",st_gid);
}


int main(int argc,char*argv[])
{
struct stat a;
int i,j,k,b;
k=lstat(argv[1],&a);
b=a.st_mode&S_IFMT;
switch(b)
{
case S_IFREG:printf("\n-");
break;
case S_IFDIR:printf("\nd");
break;
case S_IFBLK:printf("\nb");
break;
case S_IFCHR:printf("\nc");
break;
case S_IFIFO:printf("\nf");
break;
case S_IFLNK:printf("\nl");
break;
}
for(i=1,j=1<<8;i<10;i++,j>>=1)
{
if(!(i%3==0))
{
switch(i)
{
case 1:
if(a.st_mode&j)
printf("r");
else
printf("-");
break;
case 2:
if(a.st_mode&j)
printf("w");
else
printf("-");
break;
case 4:
if(a.st_mode&j)
printf("r");
else
printf("-");
break;
case 5:
if(a.st_mode&j)
printf("w");
else
printf("-");
break;
case 7:
if(a.st_mode&j)
printf("r");
else
printf("-");
break;
case 8:
if(a.st_mode&j)
printf("w");
else
printf("-");
break;
}
}
else if(i==3)
{
if((a.st_mode&j)&&(a.st_mode&S_ISUID))
printf("s");
else if(a.st_mode&j)
printf("x");
else if(a.st_mode&S_ISUID)
printf("S");
else
printf("-");
}
else if(i==6)
{
if((a.st_mode&j)&&(a.st_mode&S_ISGID))
printf("g");
else if(a.st_mode&j)
printf("x");
else if(a.st_mode&S_ISGID)
printf("G");
else
printf("-");
}
else if(i==9)
{
if((a.st_mode&j)&&(a.st_mode&S_ISVTX))
printf("s ");
else if(a.st_mode&j)
printf("x ");
else if(a.st_mode&S_ISVTX)
printf("S ");
else
printf("- ");
}
}
printf("%d ",a.st_nlink);
printgid(a.st_uid,a.st_gid);
if((b==S_IFBLK)||(b==S_IFCHR))
{
printf("%d ",a.st_rdev>>8);
printf("%d ",a.st_rdev&0x00FF);
}
else
{
printf("%d ",a.st_size);
printf("%s ",ctime(&a.st_mtime));
printf("%s\n",argv[1]);
return 0;
}
}
