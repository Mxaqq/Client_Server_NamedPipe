#include "ServerApp.hpp"
#include <iostream>
#include <chrono>
#include <thread>

ServerApp::ServerApp(const std::string& request_pipe, const std::string& response_pipe)
    : transport_(request_pipe, response_pipe) {}

void ServerApp::run() {
    std::cout << "Server has woken up and is now listening for requests..." << std::endl;

    while (true) {
        try {
            auto request = transport_.read();
            std::cout << "Request received." << std::endl;

            auto [type, data] = Protocol::deserialize(request);
            handleRequest(type, data);
        }
        catch (const std::exception& e) {
            std::cerr << "Error reading from pipe: " << e.what() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void ServerApp::handleRequest(const Protocol::MessageType& type, const std::vector<uint8_t>& data) {
    switch (type) {
        case Protocol::KEEP_ALIVE:
            transport_.write(Protocol::serialize(Protocol::KEEP_ALIVE, {}));
            std::cout << "Handled Keep Alive\n";
            break;

        case Protocol::GET_STATUS:
            transport_.write(Protocol::serialize(Protocol::GET_STATUS, {'A', 'l', 'l', ' ', 'o', 'k'}));
            std::cout << "Handled Get Status\n";
            break;

        default:
            std::cout << "Unhandled request type\n";
    }
}