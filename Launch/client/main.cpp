#include "ClientApp.hpp"

int main() {
    ClientApp client("/tmp/fifo_request", "/tmp/fifo_response");
    client.run();
    return 0;
}