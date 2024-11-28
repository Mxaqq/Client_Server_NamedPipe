#include "ServerApp.hpp"

int main() {
    ServerApp server("/tmp/fifo_response", "/tmp/fifo_request");
    server.run();
    return 0;
}