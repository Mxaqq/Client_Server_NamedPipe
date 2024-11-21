#ifndef CLIENT_APP_HPP
#define CLIENT_APP_HPP

#include "NamedPipeTransport.hpp"
#include "Protocol.hpp"

class ClientApp {
public:
    ClientApp(const std::string& request_pipe, const std::string& response_pipe);

    void run();

private:
    NamedPipeTransport transport_;

    void sendKeepAlive();
    void sendGetStatus();
};

#endif 