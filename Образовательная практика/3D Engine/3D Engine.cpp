#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

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
#include "MathFuncsDll.h"

using namespace std;

//структура данных для общего доступа основного и треда пайпов
typedef struct
{
	//дескрипторы событий
	HANDLE  hePipeStart;
	HANDLE  hePipeReply;
	//дескрипторы пайпов
	HANDLE  child_in;
	HANDLE  parent_out;
	HANDLE  child_out;
	HANDLE  parent_in;
	//буфера
	char    read[1024];     //буфер для чтения данных
	char    send[1024];     //передаваемое значение
}TheadParms;

//тред пайпов
BOOL FAR PASCAL PipesProc(LPSTR lpData)
{
	TheadParms* ptp = (TheadParms*)lpData;     //переданный параметр - адрес общих данных
	DWORD       num;                            //количество переданых/прочитаных байт

	while (1)                                   //бесконечный цикл
	{
		WaitForSingleObject(ptp->hePipeStart, INFINITE);   //ждем бесконечно событие

		//передача данных
		WriteFile(ptp->child_in, ptp->send, lstrlenA(ptp->send), &num, NULL);   //передаем готовые данные
		std::cout << "Данные переданы: " << ptp->send;                            //выведем переданные данные здесь

		//чтение данных
		ReadFile(ptp->child_out, ptp->read, 1023, &num, NULL);                  //читаем ответ в буфер
		SetEvent(ptp->hePipeReply);                                             //и взводим событие готовности
	}
}

void SIGINT_handle(int sig_num)
{

}

typedef BOOL(WINAPI* SETCONSOLEFONT)(HANDLE, DWORD);     // прототип недокументированый функции
SETCONSOLEFONT SetConsoleFont;

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.dwFontSize.X = 10;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
	SetCurrentConsoleFontEx(Handle, TRUE, &fontInfo);
}

int main() {
	setlocale(0, "");

	SECURITY_ATTRIBUTES sa;//атрибуты защиты канала
	sa.lpSecurityDescriptor = NULL; //защита по умолчанию
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = true;//разрешаем наследование дескрипторов

//обработка ошибок
	SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX | SEM_NOALIGNMENTFAULTEXCEPT);

	TheadParms tp = {};         //структура общих данных

	//создаем анонимные каналы
	CreatePipe(&tp.parent_out, &tp.child_in, &sa, 0); //канал для stdin дочернего процесса
	CreatePipe(&tp.child_out, &tp.parent_in, &sa, 0); //канал для stdout дочернего процесса

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	//  si.wShowWindow = SW_HIDE;//скрываем окно дочернего процесса
		//подменяем дескрипторы
	si.hStdOutput = tp.parent_in;
	si.hStdError = tp.parent_in;
	si.hStdInput = tp.parent_out;

	//Создаём дочерний процесс
	WCHAR ModuleName[] = L"ClientApp.exe";
	PROCESS_INFORMATION pi;
	CreateProcess(ModuleName, NULL, NULL, NULL, TRUE, ABOVE_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);                // здесь будут дескрипторы и идентификаторы нового процесса и его первичного потока

	//Создаем события для синхнонизации
	tp.hePipeStart = CreateEvent(NULL,   // no security
		FALSE,  // explicit auto reset req
		FALSE,  // initial event reset
		NULL);  // no name

	tp.hePipeReply = CreateEvent(NULL,   // no security
		FALSE,  // explicit auto reset req
		FALSE,  // initial event reset
		NULL);  // no name

//Создаем тред пайпов
	DWORD dwPipesThreadID;
	HANDLE hPipesThread = CreateThread((LPSECURITY_ATTRIBUTES)NULL, 0,
		(LPTHREAD_START_ROUTINE)PipesProc, &tp, 0, &dwPipesThreadID);  //параметром передаем адрес структуры данных

	DWORD value = 0;

	string s;
	int i = 0;
	int resolution[2];
	int renderScale = 1, rayTracing = 1;
	cout << "configuration:" << endl;
	cout << "------------------------------------------------------" << endl;
	ifstream file("config.txt");
	while (getline(file, s)) {
		cout << s << endl;
		if (i == 2) {
			renderScale = stoi(s);
		} else if(i == 3) {
			rayTracing = stoi(s);
		}
		else {
			resolution[i] = stoi(s);
		}
		i++;
	}

	cout << "------------------------------------------------------" << endl;
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Текущее время и дата: %s", asctime(timeinfo));

	cout << " " << endl;
	cout << "Feodor Plotnikov" << endl;
	cout << "------------------------------------------------------" << endl;

	file.close();
	std::sort(std::begin(resolution), std::end(resolution));
	system("pause");

	int width = resolution[1] * renderScale;
	int height = resolution[0] * renderScale;
	SetWindow(width, height);
	float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;
	char gradient[] = " .:!/r(l1Z4H9W8$@ ";
	int gradientSize = std::size(gradient) - 2;

	wchar_t* screen = new wchar_t[width * height];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	for (int t = 0; t < 10000; t++) {
		signal(SIGINT, SIGINT_handle);
		long start_time = clock();
		vec3 light = MathFuncs::MyMathFuncs::norm(vec3(-0.5, 0.5, -1.0));
		vec3 spherePos = vec3(0, 0, 0);
		vec3 boxPos0 = vec3(-3 - 1 * sin(t * 0.1), 0, 0);
		vec3 boxPos1 = vec3(3 + 1 * sin(t * 0.1), 0, 0);
		vec3 boxPos2 = vec3(0, -3 - 1 * sin(t * 0.1), 0);
		vec3 boxPos3 = vec3(0, 3 + 1 * sin(t * 0.1), 0);
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				vec2 uv = vec2(i, j) / vec2(width, height) * 2.0f - 1.0f;
				uv.x *= aspect * pixelAspect;
				vec3 ro = vec3(-6, 0, 0);
				vec3 rd = MathFuncs::MyMathFuncs::norm(vec3(2, uv));
				ro = MathFuncs::MyMathFuncs::rotateY(ro, 0.25);
				rd = MathFuncs::MyMathFuncs::rotateY(rd, 0.25);
				ro = MathFuncs::MyMathFuncs::rotateZ(ro, 0.25);
				rd = MathFuncs::MyMathFuncs::rotateZ(rd, 0.25);
				ro = MathFuncs::MyMathFuncs::rotateX(ro, sin(t * 0.01));
				rd = MathFuncs::MyMathFuncs::rotateX(rd, sin(t * 0.01));
				ro = MathFuncs::MyMathFuncs::rotateZ(ro, t * 0.05);
				rd = MathFuncs::MyMathFuncs::rotateZ(rd, t * 0.05);
				float diff = 1;
				for (int k = 0; k < rayTracing; k++) {
					float minIt = 99999;
					vec2 intersection = MathFuncs::MyMathFuncs::sphere(ro - spherePos, rd, 1);
					vec3 n = 0;
					float albedo = 1;
					if (intersection.x > 0) {
						vec3 itPoint = ro - spherePos + rd * intersection.x;
						minIt = intersection.x;
						n = MathFuncs::MyMathFuncs::norm(itPoint);
					}
					vec3 boxN = 0;
					intersection = MathFuncs::MyMathFuncs::box(ro - boxPos0, rd, 0.5, boxN);
					if (intersection.x > 0 && intersection.x < minIt) {
						minIt = intersection.x;
						n = boxN;
					}
					boxN = 0;
					intersection = MathFuncs::MyMathFuncs::box(ro - boxPos1, rd, 0.5, boxN);
					if (intersection.x > 0 && intersection.x < minIt) {
						minIt = intersection.x;
						n = boxN;
					}
					boxN = 0;
					intersection = MathFuncs::MyMathFuncs::box(ro - boxPos2, rd, 0.5, boxN);
					if (intersection.x > 0 && intersection.x < minIt) {
						minIt = intersection.x;
						n = boxN;
					}
					boxN = 0;
					intersection = MathFuncs::MyMathFuncs::box(ro - boxPos3, rd, 0.5, boxN);
					if (intersection.x > 0 && intersection.x < minIt) {
						minIt = intersection.x;
						n = boxN;
					}
					intersection = MathFuncs::MyMathFuncs::plane(ro - vec3(0, 0, 0), rd, vec3(0, 0, -1), 1);
					if (intersection.x > 0 && intersection.x < minIt) {
						minIt = intersection.x;
						n = vec3(0, 0, -1);
						albedo = 0.5;
					}
					if (minIt < 99999) {
						diff *= (MathFuncs::MyMathFuncs::dot(n, light) * 0.5 + 0.5) * albedo;
						ro = ro + rd * (minIt - 0.01);
						rd = MathFuncs::MyMathFuncs::reflect(rd, n);
					}
					else break;
				}
				int color = (int)(diff * 17);
				color = MathFuncs::MyMathFuncs::clamp(color, 0, gradientSize);
				char pixel = gradient[color];
				screen[i + j * width] = pixel;
			}
		}
		screen[width * height - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, width * height, { 0, 0 }, &dwBytesWritten);
		long end_time = clock();
		float diffTime = end_time - start_time;
		value = diffTime;
		wsprintfA(tp.send, "%d\n", value);        //формируем числовую строку с символом '\n' в конце

		SetEvent(tp.hePipeStart);                   //даем отмажку для треда пайпов
	}
}