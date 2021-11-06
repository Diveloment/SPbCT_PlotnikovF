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
    } ; 
    struct mybuf buf; 
    int fd; 
    char text[100]; 
    int textLen; 
    ofstream text1;
    int id = getpid();
    string name1="Server."+ to_string(id);
    text1.open(name1);
    if((key_s=ftok("SERVER.cpp",0))==-1)
    { 
    perror("Ошибка создания ключа"); 
    return 1; 
    } 
    if((key_c=ftok("SERVER.cpp",0))==-1)
    { 
    perror("Ошибка создания ключа"); 
    return 1; 
    }

    while(1){

    if((fd=msgget(key_s, 0))==-1) { 
    perror("Ошибка создания очереди"); 
    return 1; } 
    if((fd=msgrcv(fd, &buf, sizeof(buf.mtext), 0, 0))==-1) 
    { 
    
    perror("Ошибка приема сообщения"); 
    
    return 1; 
    } 
    printf("Получен текст -> %s\n",buf.mtext);
    text1 << buf.mtext << endl;

    string line;
    ifstream in(buf.mtext); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << "File: " << line << std::endl;
            line+=line;
            strcpy(text, line.c_str());
        }
    }
    in.close();     // закрываем файл

    memset(buf.mtext, 0, sizeof(buf.mtext));
    if((fd=msgget(key_c, IPC_CREAT|0644))==-1) 
    { 
            perror("Ошибка создания очереди"); 
            return 1; 
    }
        textLen=strlen(text);
        strncpy(buf.mtext, text, textLen); 
        buf.mtype=1L; 
        if((fd=msgsnd(fd, &buf, textLen,0))==-1) 
    { 
        perror("Ошибка посылки сообщения"); 
        return 1;
    }
    memset(buf.mtext, 0, sizeof(buf.mtext)); 
    }
    return 0; 
}