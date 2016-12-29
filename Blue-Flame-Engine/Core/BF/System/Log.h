#pragma once
#include <stdio.h>
#include <Windows.h>


static void SetConsoleColor(int colorCode)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define BF_LOG_INFO(x, ...)		do { SetConsoleColor(15); printf("[INFO]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15); break; } while(true)
#define BF_LOG_WARNING(x, ...)	do { SetConsoleColor(14); printf("[WARNING]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15); break; } while(true)
#define BF_LOG_ERROR(x, ...)	do { SetConsoleColor(12); printf("[ERROR]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15); break; } while(true)
#define BF_LOG_FATAL(x, ...)	do { SetConsoleColor(79); printf("[FATAL]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15); break; } while(true)