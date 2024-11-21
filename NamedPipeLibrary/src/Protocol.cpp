#include "Protocol.hpp"
#include <stdexcept>
#include <cstring>
#include <iostream>

std::vector<uint8_t> Protocol::serialize(MessageType type, const std::vector<uint8_t>& data) {
    std::cout << "Starting serialization..." << std::endl;

    std::vector<uint8_t> packet;
    
    packet.push_back(type);
    std::cout << "Message type added: " << static_cast<int>(type) << std::endl;

    uint32_t length = data.size();
    std::cout << "Data length: " << length << std::endl;
    packet.insert(packet.end(), reinterpret_cast<uint8_t*>(&length), reinterpret_cast<uint8_t*>(&length) + sizeof(length));
    
    packet.insert(packet.end(), data.begin(), data.end());
    std::cout << "Data serialized, packet size: " << packet.size() << std::endl;

    return packet;
}

std::pair<Protocol::MessageType, std::vector<uint8_t>> Protocol::deserialize(const std::vector<uint8_t>& packet) {
    std::cout << "Starting deserialization..." << std::endl;

    if (packet.size() < 5) { 
        throw std::runtime_error("Invalid packet size");
    }

    MessageType type = static_cast<MessageType>(packet[0]);
    std::cout << "Message type extracted: " << static_cast<int>(type) << std::endl;

    uint32_t length;
    std::memcpy(&length, &packet[1], sizeof(length));
    std::cout << "Extracted data length: " << length << std::endl;

    if (packet.size() < 5 + length) {
        throw std::runtime_error("Invalid packet length");
    }

    std::vector<uint8_t> data(packet.begin() + 5, packet.begin() + 5 + length);
    std::cout << "Data extracted, size: " << data.size() << std::endl;

    return {type, data};
}