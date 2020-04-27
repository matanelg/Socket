#include"Socket.h"

namespace soc {

	Socket::Socket(string ip, int port):  // Constructure initialize members, winsock and create a socket.
		ServerSocket(NULL),init(false) {
		this->ip = ip;	
		this->port = port;		
		init = Initialize() ? CreateSocket() : false; 
	}

	bool Socket::Initialize() {		// initialize winsock.
		WSAData Ver;
		int result = WSAStartup(MAKEWORD(2, 2), &Ver);
		if (result != 0) {
			cout << "Failed initialize Winsock.  err." << WSAGetLastError() << endl;
			return false;
		}
		return true;
	}

	bool Socket::CreateSocket() {		// Create a socket.
		ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (ServerSocket == INVALID_SOCKET) {
			WSACleanup();
			cout << "Socket not created.   err." << WSAGetLastError() << endl;
			return false;
		}
		return true;
	}

	void Socket::Send(int* numbs) {		// Order 4 bytes numbers into char array and send the data.
		memset(send_message, 0, package_size);
		for (int i = 0; i < data_numbs; i++) {
			char* number = (char*)&numbs[i];
			for (int u = 0; u < 4; u++) {
				send_message[u + i * 4] = *(number + u);
			}
		}
		send(ServerSocket, (const char*)send_message, package_size, 0);
	}

	int* Socket::Recive() {		 // Collect every 4 byte in the reciving char array and assemble the numbers data.
		memset(recive_message, 0, package_size);
		memset(Data, 0, data_numbs);
		recv(ClientSocket, recive_message, package_size, 0);
		for (int j = 0; j < data_numbs; j++) {
			*(Data + j) = 0;
			for (int i = 3 + j * 4; i >= j * 4; i--) {
				*(Data + j) += (unsigned char)recive_message[i];
				if (i % 4 != 0) *(Data + j) <<= 8;
			}
		}
		return Data;
	}


	Socket::~Socket() { // Destracture not really necessary. 
		cout << "Socket Calss destroyed. " << endl; 
	}
}

namespace soc {

	Server::Server(string ip, int port) : // Constructore initialize members, listen for connection , accept connection and close listen socket.
		Socket(ip, port) {
		init = init ? Bind() : false;
		listen(ServerSocket, SOMAXCONN);
		if (init = init ? Accept() : false) {
			closesocket(ServerSocket);
		}
	};

	bool Server::Bind() { // Bind ip address and port to a socket.
		sockaddr_in data;
		data.sin_family = AF_INET;
		data.sin_port = htons(port);
		data.sin_addr.S_un.S_addr = INADDR_ANY;

		int Bind = bind(ServerSocket, (sockaddr*)&data, sizeof(data));
		if (Bind != 0) {
			cout << "Socket failed binding with the ip address & port.   err." << WSAGetLastError() << endl;
			closesocket(ServerSocket);
			WSACleanup();
			return false;
		}
		else {
			cout << "Socket successfuly bind to:";
			cout << "    ip address = " << ip;
			cout << "    Port = " << ntohs(data.sin_port) << endl << endl;
			cout << "Waiting for connection..." << endl;
		}
		return true;
	}

	bool Server::Accept() { // Accept Client connection.
		sockaddr_in client_data;
		int size = sizeof(client_data);
		ClientSocket = accept(ServerSocket, (sockaddr*)&client_data, &size);

		char client_host[NI_MAXHOST];
		ZeroMemory(client_host, NI_MAXHOST);

		char client_ip[NI_MAXHOST];
		ZeroMemory(client_ip, NI_MAXHOST);

		char client_port[NI_MAXSERV];
		ZeroMemory(client_port, NI_MAXSERV);
		
		if (getnameinfo((sockaddr*)&client_data, sizeof(client_data), client_host, NI_MAXHOST, client_port, NI_MAXSERV, 0) == 0) {
			cout << "Client successfuly connect: ";
			inet_ntop(AF_INET, &client_data.sin_addr, client_ip, NI_MAXHOST);
			cout << "      Client ip address: " << client_ip;
			cout << "      Client port: " << client_port << endl;
			return true;
		}
		return false;
	}

	Server::~Server() { // Closing socket and winsock.
		if (init == true) { 
			closesocket(ClientSocket); 
			WSACleanup(); 
			cout << "Server Calss destroyed. " << endl; } 
	};
}

namespace soc {
	Client::Client(string ip, int port) : // Constructore initialize members and connect to server.
		Socket(ip, port) {
		init = Connect() ? true : false;
	};

	bool Client::Connect() { // Connect to server.
		sockaddr_in data1;
		data1.sin_family = AF_INET;
		data1.sin_port = htons(port);
		inet_pton(AF_INET, ip.c_str(), &data1.sin_addr);

		int Connect = connect(ServerSocket, (sockaddr*)&data1, sizeof(data1));
		if (Connect != 0) {
			cout << "Client can not connect to the server." << endl;
			closesocket(ServerSocket);
			WSACleanup();
			return false;
		}
		else {
			cout << "Client successfuly connect to:";
			cout << "    Server ip address = " << ip;
			cout << "    Port = " << ntohs(data1.sin_port) << endl << endl;;
		}
		return true;
	}

	Client::~Client() { // Closing socket and winsock.
		if (init == true) { 
			closesocket(ServerSocket); 
			WSACleanup(); 
			cout << "Client Calss destroyed. " << endl; } 
	};

}
