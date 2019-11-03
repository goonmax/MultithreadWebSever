#include "websocket_huddle.hpp"
#include <iostream>


websocket_huddle::websocket_huddle(tcp::socket && socket, boost::shard_ptr<mutex> const & state) : ws_(std::move(socket)), state_(state)
{

}

websocket_huddle::~websocket_huddle()
{
	// gets rid of the connection on the active sessions
	state_->leave(this);
}

