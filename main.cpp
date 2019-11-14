#include <iostream>
#include "TcpListener.hpp"
#include "mutex.hpp"
#include <boost/asio/signal_set.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <vector>
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;
string read_(tcp::socket & socket) {
boost::asio::streambuf buf;
boost::asio::read_until( socket, buf, "\n"  );
string data = boost::asio::buffer_cast<const char*>(buf.data());
return data;								
}
void send_(tcp::socket & socket, const string& message) {
	       const string msg = message + "\n";
		          boost::asio::write( socket, boost::asio::buffer(message)  );				  
}


int main(int argc, char* argv[])
{
      boost::asio::io_service io_service;
	  //listen for new connection
	  tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234 ));
	  //      //socket creation 
	    tcp::socket socket_(io_service);
	  //            //waiting for connection
	    acceptor_.accept(socket_);
		string message = read_(socket_);
		cout << message << endl;
        send_(socket_, "Hello From Server!");
		cout << "Servent sent Hello message to Client!" << endl;
										  return 0;
//  connonect to the port here and starting servering on that port 
}
