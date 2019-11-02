#ifndef CPPCON2018_ASIO_HPP
#define CPPCON2018_ASIO_HPP


#include <boost/asio.hpp>

namespace net = boost::asio;                    // namespace asio
using tcp = net::ip::tcp;                       // from <boost/asio/ip/tcp.hpp>
using error_code = boost::system::error_code;   // from <boost/system/error_code.hpp>

#endif
