#pragma once
#ifdef BF_PLATFORM_WINDOWS

#include <stdio.h>
#include <Windows.h>

static void SetConsoleColor(int colorCode)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define BF_LOG_INFO(x, ...)		do { SetConsoleColor(15); printf("[INFO]: "); printf(x, __VA_ARGS__); printf("\n"); SetConsoleColor(15); } while(false)
#define BF_LOG_WARNING(x, ...)	do { SetConsoleColor(14); printf("[WARNING]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15); } while(false)
#define BF_LOG_ERROR(x, ...)	do { SetConsoleColor(12); printf("[ERROR]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15); } while(false)
#define BF_LOG_FATAL(x, ...)	do { SetConsoleColor(79); printf("[FATAL]: "); printf(x, __VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); SetConsoleColor(15); } while(false)

#elif BF_PLATFORM_ANDROID

#include <strings.h>
#include <android/log.h>

#define BF_LOG_INFO(...)	do { __android_log_print(ANDROID_LOG_INFO,  "Blue Flame Engine: [INFO]", __VA_ARGS__); } while(false)
#define BF_LOG_WARNING(...) do { __android_log_print(ANDROID_LOG_WARN,  "Blue Flame Engine: [WARNING]", __VA_ARGS__); } while(false)
#define BF_LOG_ERROR(...)	do { __android_log_print(ANDROID_LOG_ERROR, "Blue Flame Engine: [ERROR]", __VA_ARGS__); } while(false)
#define BF_LOG_FATAL(...)	do { __android_log_print(ANDROID_LOG_FATAL, "Blue Flame Engine: [FATAL]", __VA_ARGS__); } while(false)

#elif BF_PLATFORM_WEB
#include <stdio.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define BF_LOG_INFO(...)	do { printf("[INFO]: "); printf(__VA_ARGS__); printf("\n"); } while(false)
#define BF_LOG_WARNING(...)	do { printf("[WARNING]: "); printf(__VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); } while(false)
#define BF_LOG_ERROR(...)	do { printf("[ERROR]: "); printf(__VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); } while(false)
#define BF_LOG_FATAL(...)	do { printf("[FATAL]: "); printf(__VA_ARGS__); printf(" Filename: %s Line: %d\n", __FILENAME__, __LINE__); } while(false)

#endif