#pragma once
#include "stdafx.h"

class SocketAddressFactory
{
public:
	static SocketAddressPtr CreateIPv4FromString(const string& inString) // inString�� ip : port or ip����
	{
		auto pos = inString.find_last_of(':');  // ':'�� ��ã���� string::npos��ȯ
		string host, service;
		if (pos != string::npos)  // �ݷ��� �ִٸ� host -> ip, service -> port��ȣ
		{
			host = inString.substr(0, pos);
			service = inString.substr(pos + 1);
		}
		else 
		{
			host = inString;
			service = "0";
		}
		addrinfo hint;
		memset(&hint, 0, sizeof(hint));
		hint.ai_family = AF_INET;  // af�� ipv4��

		addrinfo* result = nullptr;
		int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);
		addrinfo* initResult = result;

		if (error != 0 && result != nullptr)
		{
			freeaddrinfo(initResult);
			return nullptr;
		}

		while (!result->ai_addr && result->ai_next)
		{
			result = result->ai_next;
		}

		if (!result->ai_addr)
		{
			freeaddrinfo(initResult);
			return nullptr;
		}

		auto toRet = std::make_shared<SocketAddress>(*result->ai_addr);

		freeaddrinfo(initResult);
		return toRet;
	};
};

