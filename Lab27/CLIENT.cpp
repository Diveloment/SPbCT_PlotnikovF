#include <stdio.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
int main() 
{ 
    key_t key_s, key_c; 
    struct mybuf 
{ 
    long mtype; 
    char mtext[100]; 
}; 
    struct mybuf buf;
    int fd; 
    char text[100]; 
    int textLen;
    ofstream text1;
    int id = getpid();
    string name1="Client."+ to_string(id);
    text1.open(name1);
    if((key_s=ftok("SERVER.cpp",0))==-1 )
    { 
    perror("Ошибка создания ключа"); 
    return 1; 
    } 
    if((key_c=ftok("SERVER.cpp",0))==-1 )
    { 
    perror("Ошибка создания ключа"); 
    return 1; 
    }

    while(1)
    {

        if((fd=msgget(key_s, IPC_CREAT|0644))==-1) 
        { 
            perror("Ошибка создания очереди"); 
            return 1; 
        } 
        printf("Ввести текст\n"); 
        std::cin >> text; 
        textLen=strlen(text); 
        strncpy(buf.mtext, text, textLen); 
        buf.mtype=1L; 
        if((fd=msgsnd(fd, &buf, textLen,0))==-1) 
        { 
        perror("Ошибка посылки сообщения"); 
        return 1;
        }
        memset(buf.mtext, 0, sizeof(buf.mtext)); 

        if((fd=msgget(key_c, 0))==-1) 
    { 
        perror("Ошибка создания очереди"); 
        return 1; } 
        if((fd=msgrcv(fd, &buf, sizeof(buf.mtext), 0, 0))==-1) 
        { 
        perror("Ошибка приема сообщения"); 
        return 1; 
        } 
        printf("Получен текст -> %s\n",buf.mtext); 
        text1 << buf.mtext << endl;

        ofstream out;          // поток для записи
        out.open(text); // окрываем файл для записи
        if (out.is_open())
        {
            out << buf.mtext << endl;
        }
        out.close();
        rename(text, "result.txt");

        memset(buf.mtext, 0, sizeof(buf.mtext));  

    }

return 0; 
}