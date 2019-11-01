#pragma once 
#include <iostream>
#include <string>
#include <sstream>
#include <boost/aligned_storage.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>





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
