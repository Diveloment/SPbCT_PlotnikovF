/* Сервер. Создает FIFO и ожидает сообщение */  
#include <iostream>  
#include <stdio.h>  
#include <errno.h>  
#include <sys/types.h>  
#include <unistd.h>  
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <queue>
#include <string.h>
#include <dirent.h>
#define NAME "sfifo.cc"  

using namespace std;

int main()
 
{  int fd;  char buf[80]; 
int file_count = 0;
int dir_count = 0;
int total = 0;
unlink(NAME);  
if(mkfifo(NAME, S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO))  
{ perror("Ошибка FIFO");   return 1;  
}  
if((fd=open(NAME, O_RDWR))==-1)  
{ perror("Ошибка открытия файла сервера");  
}  
read(fd, buf, sizeof(buf));
cout << "Получено->" << buf << endl;

DIR * dirp;
struct dirent * entry;

dirp = opendir("/home/SHPK/Projects/Lab26"); 
while ((entry = readdir(dirp)) != NULL) {
    total++;
    if (entry->d_type == DT_REG) {
         file_count++;
    }
}
dir_count = file_count;
closedir(dirp);
cout << file_count << endl;
memset(&buf[0], 0, sizeof(buf));
sprintf(buf,"%d",file_count);

cout << buf << endl;
write(fd, buf, strlen(buf));
sleep(1);
close(fd);
 
unlink(NAME);  return 0; }