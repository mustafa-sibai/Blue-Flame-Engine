template<typename T>
inline void Debug::Log(T value, Debug::LogLevel level)
{
	switch (level)
	{
		case Debug::LogLevel::Info:
		{		
			std::cout << "[INFO]: " << value;
			break;
		}
		case Debug::LogLevel::Warning:
		{		
			std::cout << "[WARNING]: " << value;
			break;
		}
		case Debug::LogLevel::Error:
		{			
			std::cout << "[ERROR]: " << value;
			break;
		}
		case Debug::LogLevel::Fatal:
		{
			std::cout << "[FATAL]: " << value;
			break;
		}
		default:
		{
			break;
		}
	}
}

#ifdef BFE_PLATFORM_WINDOWS

static void SetConsoleColor(int colorCode)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}

#endif

#if defined(BFE_PLATFORM_WINDOWS) || defined(BFE_PLATFORM_WEB) || defined(BFE_PLATFORM_LINUX)

#define __filename__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define BFE_LOG_INFO(x, ...)		do { BF::System::SetConsoleColor(15); BF::System::Debug::Log(x, BF::System::Debug::LogLevel::Info);		printf(__VA_ARGS__); printf("\n");												 BF::System::SetConsoleColor(15); } while(false)
#define BFE_LOG_WARNING(x, ...)	do { BF::System::SetConsoleColor(14); BF::System::Debug::Log(x, BF::System::Debug::LogLevel::Warning);	printf(__VA_ARGS__); printf(" Filename: %s Line: %d\n", __filename__, __LINE__); BF::System::SetConsoleColor(15); } while(false)
#define BFE_LOG_ERROR(x, ...)	do { BF::System::SetConsoleColor(12); BF::System::Debug::Log(x, BF::System::Debug::LogLevel::Error);	printf(__VA_ARGS__); printf(" Filename: %s Line: %d\n", __filename__, __LINE__); BF::System::SetConsoleColor(15); } while(false)
#define BFE_LOG_FATAL(x, ...)	do { BF::System::SetConsoleColor(79); BF::System::Debug::Log(x, BF::System::Debug::LogLevel::Fatal);	printf(__VA_ARGS__); printf(" Filename: %s Line: %d\n", __filename__, __LINE__); BF::System::SetConsoleColor(15); } while(false)

#define BFE_IS_NULL(x) x == NULL ? NULL : x; if(x == NULL) BFE_LOG_FATAL(#x, " is NULL");

#elif defined(BFE_PLATFORM_ANDROID)
/*
#define BFE_LOG_INFO(...)	do { __android_log_print(ANDROID_LOG_INFO,  "Blue Flame Engine: [INFO]", __VA_ARGS__); } while(false)
#define BFE_LOG_WARNING(...) do { __android_log_print(ANDROID_LOG_WARN,  "Blue Flame Engine: [WARNING]", __VA_ARGS__); } while(false)
#define BFE_LOG_ERROR(...)	do { __android_log_print(ANDROID_LOG_ERROR, "Blue Flame Engine: [ERROR]", __VA_ARGS__); } while(false)
#define BFE_LOG_FATAL(...)	do { __android_log_print(ANDROID_LOG_FATAL, "Blue Flame Engine: [FATAL]", __VA_ARGS__); } while(false)
*/
#endif