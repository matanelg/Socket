#pragma once
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#define data_numbs 1000
#define package_size 4*data_numbs
using std::string;
using std::cout;
using std::endl;

//	Proccess Server:
//	1.Initialize winsock.
//	2.Create a socket for listening.
//	3.Bind ip address & port.
//	4.Listen for connection.
//	5.Accept connection.
//	6.Close listening socket.
//	7.Send and recive data.
//	8.Close client socket and winsock.

//	Proccess Client:
//	1.Initialize winsock.
//	2.Create a socket for connecting to server.
//	3.Connect.
//	4.Send and recive data.
//	5.Close client socket and winsock.

namespace soc
{
	class Socket {
	private:
		bool Initialize();
		bool CreateSocket();

	protected:
		bool init;
		string ip;
		int port;
		char send_message[package_size];
		char recive_message[package_size];
		int Data[data_numbs];
		SOCKET ClientSocket;
		SOCKET ServerSocket;
		Socket(string ip, int port);
		~Socket();
		
	public:
		void Send(int* numbs);
		int* Recive();
	};


	class Server :public Socket {
	private:
		bool Bind();
		bool Accept();
	public:
		Server(string ip, int port);
		~Server();
	};

	class Client :public Socket {
	private:
		bool Connect();
	public:
		Client(string ip, int port);
		~Client();
	};
}





