#pragma once
#include <WinSock2.h>
#include <ws2tcpip.h>
#include "BF/Common.h"

namespace BF
{
	namespace Network
	{
		class BFE_API Server
		{
			private:
				SOCKET listenSocket, clientSocket;
				WSADATA wsaData;
				int iResult;
				addrinfo hints;
				addrinfo *result;

			public:
				Server();
				~Server();

				void Initialize();
				void Listen();
				void Accept();
				void Run();
				void Shutdown();
				void CleanUp();
		};
	}
}