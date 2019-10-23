#pragma once 
#include <iostream>
#include <string>
#include <sstream>

class TcpListener
{

public:
	TcpListener(const char* IpAddress, int PortNumber) : IpAddress(IpAddress), PortNumber(PortNumber) {} //constractor for ipadress andportnumber
	int create();
	int start();
protected:

private:

	const char* IpAddress;
	int			PortNumber;
	int 		Socket;
};
