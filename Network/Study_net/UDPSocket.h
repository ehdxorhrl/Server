#pragma once
class UDPSocket
{
public:
	~UDPSocket();
	int Bind(const SocketAddress& inToAddress);
	
};

