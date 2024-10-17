#pragma once
#include "stdafx.h"

class SocketAddress
{
public:
	SocketAddress(uint32_t inAddress, uint16_t inport)
	{
		GetAsSockAddrIn()->sin_family = AF_INET;
		GetAsSockAddrIn()->sin_addr.S_un.S_addr = htonl(inAddress);
		GetAsSockAddrIn()->sin_port = htonl(inport);
	}

	SocketAddress(const sockaddr& inSockAddr)
	{
		memcpy(&mSockAddr, static_cast<const sockaddr*>(&inSockAddr), sizeof(mSockAddr));
	}

private:
	sockaddr mSockAddr;

	sockaddr_in* GetAsSockAddrIn()
	{
		return reinterpret_cast<sockaddr_in*>(&mSockAddr);
	}
};

using SocketAddressPtr = shared_ptr<SocketAddress>;

