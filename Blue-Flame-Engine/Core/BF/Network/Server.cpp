#include "Server.h"
#include "BF/System/Log.h"

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
			BF_LOG_INFO("Initializing Winsock 2");
			iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
			if (iResult != 0) 
				BF_LOG_ERROR("WSAStartup failed with error: %d\n", iResult);

			ZeroMemory(&hints, sizeof(hints));
			hints.ai_family = AF_INET;
			hints.ai_socktype = SOCK_STREAM;
			hints.ai_protocol = IPPROTO_TCP;
			hints.ai_flags = AI_PASSIVE;

			// Resolve the server address and port
			iResult = getaddrinfo(NULL, SERVER_PORT, &hints, &result);
			if (iResult != 0) 
			{
				BF_LOG_ERROR("getaddrinfo failed with error: %d\n", iResult);
				WSACleanup();
			}

			// Create a SOCKET for connecting to server
			listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
			if (listenSocket == INVALID_SOCKET) 
			{
				BF_LOG_ERROR("socket failed with error: %ld\n", WSAGetLastError());
				freeaddrinfo(result);
				WSACleanup();
			}

			BF_LOG_INFO("Binding listening socket");
			// Setup the TCP listening socket
			iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
			if (iResult == SOCKET_ERROR) 
			{
				BF_LOG_ERROR("bind failed with error: %d\n", WSAGetLastError());
				freeaddrinfo(result);
				closesocket(listenSocket);
				WSACleanup();
			}

			freeaddrinfo(result);
		}

		void Server::Listen()
		{
			BF_LOG_INFO("listening...");
			iResult = listen(listenSocket, SOMAXCONN);
			if (iResult == SOCKET_ERROR) 
			{
				BF_LOG_ERROR("listen failed with error: %d\n", WSAGetLastError());
				closesocket(listenSocket);
				WSACleanup();
			}
		}

		void Server::Accept()
		{
			BF_LOG_INFO("Waiting for client to connect...");
			clientSocket = accept(listenSocket, NULL, NULL);
			if (clientSocket == INVALID_SOCKET)
			{
				BF_LOG_ERROR("accept failed with error: %d\n", WSAGetLastError());
				closesocket(listenSocket);
				WSACleanup();
			}

			BF_LOG_INFO("Client connected !");
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
				printf("shutdown failed with error: %d\n", WSAGetLastError());
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