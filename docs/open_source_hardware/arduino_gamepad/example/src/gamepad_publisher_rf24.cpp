#include "gamepad_publisher_rf24.h"

namespace emakefun {

GamepadPublisherRf24::GamepadPublisherRf24() = default;

bool GamepadPublisherRf24::Initialize(
    const uint8_t ce_pin, const uint8_t cs_pin, uint8_t channel, uint8_t address_width, uint64_t address) {
  rf24_.begin(ce_pin, cs_pin);
  rf24_.setAddressWidth(address_width);
  rf24_.openWritingPipe(address);
  rf24_.setChannel(channel);
  rf24_.setPALevel(RF24_PA_MAX);  // MIN power low rage
  rf24_.setDataRate(RF24_1MBPS);  // Minimum speed
  rf24_.stopListening();          // Stop Receiving and start transmitting
  rf24_.enableDynamicPayloads();
  return true;
}

void GamepadPublisherRf24::OnPacket(const uint8_t* packet, uint8_t length) {
  rf24_.write(packet, length);
}
}  // namespace emakefun