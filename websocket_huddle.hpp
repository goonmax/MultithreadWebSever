#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include "net.hpp"
#include "mutex.hpp"
#include <boost/beast.hpp>

namespace beast = boost::beast;                 // from <boost/beast.hpp>
namespace http = beast::http;                   // from <boost/beast/http.hpp>
namespace websocket = beast::websocket;  

class mutex;
class websocket_huddle : public boost::enable_shared_from_this<websocket_huddle>
{
    beast::flat_buffer buffer_;
    websocket::stream<beast::tcp_stream> ws_;
    boost::shared_ptr<mutex> state_;
    std::vector<boost::shared_ptr<std::string const >> queue_;
    void fail(beast::error_code ec, char const* what);
    void on_accept(beast::error_code ec);
    void on_read(beast::error_code ec, std::size_t bytes_transferred);
    void on_write(beast::error_code ec, std::size_t bytes_transferred);

    public:
    websocket_huddle(tcp::socket&& socket, boost::shared_ptr<mutex> const& state);
    ~websocket_huddle();
    template<class Body, class Allocator>
        void run(http::request<Body, http::basic_fields<Allocator>> req);
    void send(boost::shared_ptr<std::string const> const& ss);
    private:
    void on_send(boost::shared_ptr<std::string const> const& ss);
};

    template<class Body, class Allocator>
void websocket_huddle::run(http::request<Body, http::basic_fields<Allocator>> req)
{
    // Set suggested timeout settings for the websocket
    ws_.set_option(websocket::stream_base::timeout::suggested(beast::role_type::server));
    ws_.set_option(websocket::stream_base::decorator([] (websocket::response_type & res)
                {
                res.set(http::field::server,
                        std::string(BOOST_BEAST_VERSION_STRING) +
                        " websocket-chat-multi");
                }));	

    // Accept the websocket handshake
    ws_.async_accept( req, beast::bind_front_handler(&websocket_huddle::on_accept, shared_from_this()));
}



