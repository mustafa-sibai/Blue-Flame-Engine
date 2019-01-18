#include "Server.h"
#include "BF/System/Debug.h"

#define SERVER_PORT "27015"

namespace BF
{
	namespace Network
	{
		Server::Server() :
			iResult(0), listenSocket(INVALID_SOCKET), clientSocket(INVALID_SOCKET)
		{
		}

		Server::~Server()
		{
		}

		void Server::Initialize()
		{
			BFE_LOG_INFO("Initializing Winsock 2", "");
			iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
			if (iResult != 0) 
				BFE_LOG_ERROR("WSAStartup failed with error: " + std::to_string(iResult), "");

			ZeroMemory(&hints, sizeof(hints));
			hints.ai_family = AF_INET;
			hints.ai_socktype = SOCK_STREAM;
			hints.ai_protocol = IPPROTO_TCP;
			hints.ai_flags = AI_PASSIVE;

			// Resolve the server address and port
			iResult = getaddrinfo(NULL, SERVER_PORT, &hints, &result);
			if (iResult != 0) 
			{
				BFE_LOG_ERROR("getaddrinfo failed with error: " + std::to_string(iResult), "");
				WSACleanup();
			}

			// Create a SOCKET for connecting to server
			listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
			if (listenSocket == INVALID_SOCKET) 
			{
				BFE_LOG_ERROR("socket failed with error: " + std::to_string(WSAGetLastError()), "");
				freeaddrinfo(result);
				WSACleanup();
			}

			BFE_LOG_INFO("Binding listening socket", "");
			// Setup the TCP listening socket
			iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
			if (iResult == SOCKET_ERROR) 
			{
				BFE_LOG_ERROR("bind failed with error: " + std::to_string(WSAGetLastError()), "");
				freeaddrinfo(result);
				closesocket(listenSocket);
				WSACleanup();
			}

			freeaddrinfo(result);
		}

		void Server::Listen()
		{
			BFE_LOG_INFO("listening...", "");
			iResult = listen(listenSocket, SOMAXCONN);
			if (iResult == SOCKET_ERROR) 
			{
				BFE_LOG_ERROR("listen failed with error: " + std::to_string(WSAGetLastError()), "");
				closesocket(listenSocket);
				WSACleanup();
			}
		}

		void Server::Accept()
		{
			BFE_LOG_INFO("Waiting for client to connect...", "");
			clientSocket = accept(listenSocket, NULL, NULL);
			if (clientSocket == INVALID_SOCKET)
			{
				BFE_LOG_ERROR("accept failed with error: " + std::to_string(WSAGetLastError()), "");
				closesocket(listenSocket);
				WSACleanup();
			}

			BFE_LOG_INFO("Client connected !", "");
		}

		void Server::Run()
		{
		}

		void Server::Shutdown()
		{
			// shutdown the connection since we're done
			iResult = shutdown(clientSocket, SD_SEND);
			if (iResult == SOCKET_ERROR) 
			{
				BFE_LOG_ERROR("shutdown failed with error: " + std::to_string(WSAGetLastError()), "");
				closesocket(clientSocket);
				WSACleanup();
			}
		}

		void Server::CleanUp()
		{
			closesocket(clientSocket);
			WSACleanup();
		}
	}
}