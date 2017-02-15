#pragma once
#include <WinSock2.h>
#include <ws2tcpip.h>
#include "BF/Common.h"

namespace BF
{
	namespace Network
	{
		class BF_API Client
		{
		private:
			WSADATA wsaData;
			SOCKET ConnectSocket = INVALID_SOCKET;
			addrinfo *result = NULL;
			addrinfo *ptr = NULL;
			addrinfo hints;

			int iResult;

			public:
				Client();
				~Client();

				void Initialize();
				void Connect();
				void Run();
				void Shutdown();
				void CleanUp();
		};
	}
}