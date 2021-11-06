#include <stdio.h>  
 
#include <string.h>  
#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/msg.h>
#include <unistd.h>
 
int main()
{  
    sleep(5);
    key_t key;  
    struct mybuf {  
 
    long mtype;  
    char mtext[81];  
    };  
    
    struct mybuf buf;  
    
    int fd;
    char text[81];  
    int textLen;

    if((key=ftok("smess.c",0))==-1 ){  
        perror("Ошибка создания ключа");
        return 1;
    }

    if((fd=msgget(key, 0))==-1){  
        perror("Ошибка создания очереди");
        return 1;
    }
    printf("Получен текст -> %s\n",buf.mtext);
    return 0;
}