#pragma once
#include <stdio.h>
#include <Windows.h>

static void SetConsoleColor(int colorCode)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define BF_INFO(x, ...)		SetConsoleColor(15); printf("[INFO]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15);
#define BF_WARNING(x, ...)	SetConsoleColor(14); printf("[WARNING]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15);
#define BF_ERROR(x, ...)	SetConsoleColor(12); printf("[ERROR]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15);
#define BF_FATAL(x, ...)	SetConsoleColor(79); printf("[FATAL]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15);
