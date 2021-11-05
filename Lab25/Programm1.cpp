#include <iostream>
#include <fstream>
#include <sys/types.h> 
#include <signal.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
 
using namespace std;
 
static int alarm_fired = 0; 
void ding(int sig) { 
    alarm_fired = 1; 
}

int main()
{   
    const int max_size = 25;
    string line = "";

    ofstream out("test.txt", std::ios::app);          // поток для записи
    fstream file("test.txt");

    pid_t pid, pid2;
    pid = fork(); 
    switch(pid) { 
    case -1: 
        /* Аварийное завершение */ 
        perror("fork failed"); 
        exit(1); 
    case 0: {
        /* Дочерний процесс */ 
        sleep(1);
        pid2 = fork();
        switch(pid2) { 
        case -1: 
            /* Аварийное завершение */ 
            perror("fork failed"); 
            exit(1); 
        case 0: {
            (void)signal(SIGALRM, ding); 
            pause(); 
            if (alarm_fired) {
            if (out.is_open())
            {
                out << "Hello World!" << endl;
                cout << "Процесс 2 записал данные в файл" << endl;
            } else {
                cout << "Процесс 2 не записал данные в файл" << endl;
            }
            exit(0);
            }
        }

        }
        sleep(1);
        if (out.is_open())
        {
            out << "Hello World!" << endl;
            cout << "Процесс 1 записал данные в файл" << endl;
        } else {
            cout << "Процесс 1 не записал данные в файл" << endl;
        }
        kill(pid2, SIGALRM);
        exit(0); 
    }
    }

    int size = 0;
    while (size < max_size) {
        sleep(1);
        file.seekg (0, ios::end);
        size = file.tellg();
    }
    cout << "Вашь фаил весит : " << size << " баит" << endl;
    file.close();
    out.close();
    ifstream in("test.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();     // закрываем файл
    return 0;
}