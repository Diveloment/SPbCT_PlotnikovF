#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <csignal>
#include <conio.h>
#include <cstdio>

using namespace std;

int main()
{
    SetFileAttributes(L"log.txt", FILE_ATTRIBUTE_NORMAL);
    std::ofstream erase("log.txt", std::ios::out);
    erase.close();
    std::ofstream out("log.txt", std::ios::app);
    SetFileAttributes(L"log.txt", FILE_ATTRIBUTE_READONLY);

    while (true)
    {
        string t;
        std::cin >> t;
        if (out.is_open())
        {
            out << "Frame time: " << t << " ms" << endl;
        }
        std::cout << t;
    }
    out.close();
    return 0;
}