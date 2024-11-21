#ifndef SERVER_APP_HPP
#define SERVER_APP_HPP

#include "NamedPipeTransport.hpp"
#include "Protocol.hpp"

class ServerApp {
public:
    ServerApp(const std::string& request_pipe, const std::string& response_pipe);

    void run();

private:
    NamedPipeTransport transport_;

    void handleRequest(const Protocol::MessageType& type, const std::vector<uint8_t>& data);
};

#endif 