#include "ServerApp.hpp"

int main() {
    ServerApp server("/tmp/fifo_request", "/tmp/fifo_response");
    server.run();
    return 0;
}