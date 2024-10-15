#pragma once
#include "Common.h"

class SocketAddressFactory
{
public:
	static SocketAddressPtr CreateIPv4FromString(const string& inString)
	{
		auto pos = inString.find_last_of(':');
		string host, service;
		if (pos != string::npos)
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
		hint.ai_family = AF_INET;  // af´Â ipv4·Î

		addrinfo* result = nullptr;
		int error = getaddrinfo(host.c_str(), service.c_str(), &hint, &result);
		addrinfo* initResult = result;



	};
};

