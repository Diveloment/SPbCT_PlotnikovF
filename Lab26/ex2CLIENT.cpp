/* Клиент */  
#include <iostream>  
#include <stdio.h>  
#include <errno.h>  
#include <sys/types.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <string.h>  
#include <sys/stat.h>  
#define NAME "sfifo.cc"  

using namespace std;

int main()  
 
{  char text[80]; 
int fd; 
cout<<"Ввести сообщение"<<endl;  
cin>>text;  
if((fd=open(NAME, O_RDWR))==-1) {  
 
perror("Ошибка открытия клиента");  
  return 1;  
}  
write(fd, text, strlen(text));
memset(&text[0], 0, sizeof(text));
sleep(1);
read(fd, text, sizeof(text));
cout << "Файлов в директории: " << text << endl;
close(fd);
return 0;  
 
}