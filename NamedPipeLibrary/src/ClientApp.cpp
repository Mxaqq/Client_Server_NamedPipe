#include "ClientApp.hpp"
#include <iostream>
#include <chrono>
#include <thread>

ClientApp::ClientApp(const std::string& request_pipe, const std::string& response_pipe)
    : transport_(request_pipe, response_pipe) {}

void ClientApp::run() {
    int choice;
    do {
        std::cout << "1. Send Keep Alive\n2. Get Status\n0. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                sendKeepAlive();
                break;
            case 2:
                sendGetStatus();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 0);
}

void ClientApp::sendKeepAlive() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    auto packet = Protocol::serialize(Protocol::KEEP_ALIVE, {});
    std::cout << "Invalid choice3\n";
    transport_.write(packet);
    std::cout << "Invalid choice1\n";

    auto response = transport_.read();
    std::cout << "Invalid choice2\n";
    auto [type, data] = Protocol::deserialize(response);

    if (type == Protocol::KEEP_ALIVE) {
        std::cout << "Server responded: OK\n";
    } else {
        std::cout << "Unexpected response\n";
    }
}

void ClientApp::sendGetStatus() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    auto packet = Protocol::serialize(Protocol::GET_STATUS, {});  // Сериализация пакета
    transport_.write(packet);  // Отправка сообщения серверу

    auto response = transport_.read();  // Чтение ответа от сервера
    auto [type, data] = Protocol::deserialize(response);  // Десериализация ответа

    if (type == Protocol::GET_STATUS) {
        std::string status(data.begin(), data.end());  // Преобразование в строку
        std::cout << "Server status: " << status << "\n";  // Вывод статуса
    } else {
        std::cout << "Unexpected response\n";
    }
}