#include <iostream>
#include <Windows.h>
#include <string>
#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <mutex>

using namespace std;

mutex m;

HANDLE SemaF;
int message;

HANDLE In = CreateEventA(NULL, TRUE, TRUE, "Ввод");
HANDLE Out = CreateEventA(NULL, TRUE, TRUE, "Вывод");
HANDLE Ex = CreateEventA(NULL, TRUE, TRUE, "Выход");

DWORD WINAPI Employee(LPVOID)
{
	CHAR a;
	do
	{
		Sleep(2000);
		cout << "		Состояние процесса:		     		   " << endl;
		cout << "Введите Сообщение: ";
		cout.flush();
		cin >> message;
		switch (message) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			ResetEvent(In);
			SetEvent(Ex);
			while (WaitForSingleObject(In, 1000) == WAIT_OBJECT_0);
			SetEvent(Ex);
			ReleaseSemaphore(SemaF, 1, NULL);
			return 0;
		}
		ResetEvent(In);
		WaitForSingleObject(Out, 1000);
		cout.flush();
		Sleep(2000);
		ResetEvent(In);
		SetEvent(Ex);
	} while (WaitForSingleObject(In, 1000) == WAIT_OBJECT_0);
	SetEvent(Ex);
	ReleaseSemaphore(SemaF, 1, NULL);
	return 0;
}

DWORD WINAPI Boss(LPVOID)
{
	DWORD ID1;
	HANDLE Write;
	setlocale(LC_ALL, ".1251");
	int n;
	cout << "Введите кол-во процессов для Boss: ";
	cin >> n;
	SemaF = CreateSemaphore(NULL, 0, n, NULL);
	for (int i = 0; i < n; i++)
	{
		m.lock();
		SetEvent(In);
		ResetEvent(Out);
		ResetEvent(Ex);
		Write = CreateThread(NULL, 0, Employee, NULL, 0, &ID1);
		if (Employee == NULL)
		{
			cout << "The new process is not created." << endl;
			cout << "Press any key to exit." << endl;
			cin.get();
			m.unlock();
			return GetLastError();
		}
		do
		{
			if (WaitForSingleObject(In, NULL) != WAIT_OBJECT_0)
			{
				cout << message << endl;
				cout.flush();
				SetEvent(Out);
				SetEvent(In);
			}
		} while (WaitForSingleObject(Ex, 2000) != WAIT_OBJECT_0);
		WaitForSingleObject(SemaF, INFINITE);
		m.unlock();
		cout << "Employee " << i + 1 << " завершил свою работу" << endl;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	HANDLE admin;
	DWORD ID;
	admin = CreateThread(NULL, 0, Boss, NULL, 0, &ID);
	if (admin == NULL)
	{
		Sleep(500);
		cout << "The new process is not created." << endl;
		cout << "Press any key to exit." << endl;
		Sleep(500);
		cin.get();
		Sleep(500);
		return GetLastError();
	}
	WaitForSingleObject(admin, INFINITE);
}