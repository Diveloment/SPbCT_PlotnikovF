#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, ".1251");
    int pid, i = 0;
    
    while (i < 10)
    {
        pid=fork();
        if(pid == 0){
            cout << "\n1 процесс: " << getpid() << endl;
            sleep(5);
            cout << "\n1 процесс завершил работу" << endl;
            _exit(1);
        }
        else if(pid > 0){
            cout << "\n2 процесс: " << getppid() << endl;
            sleep(5);
            cout << "\n2 процесс завершил работу" << endl;
             wait(nullptr);
        }
        else {
            perror("Fork error ");
            return -1;
        }
        sleep(3);
        i += 1;
        cout << "i: " << i << endl;
    }
    return 0;
}