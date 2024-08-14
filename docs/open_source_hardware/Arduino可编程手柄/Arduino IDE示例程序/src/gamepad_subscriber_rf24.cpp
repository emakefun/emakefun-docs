#include "gamepad_subscriber_rf24.h"

namespace emakefun {
GamepadSubscriberRf24::GamepadSubscriberRf24() = default;

bool GamepadSubscriberRf24::Initialize(
    const uint8_t ce_pin, const uint8_t cs_pin, const uint8_t channel, const uint8_t address_width, const uint64_t address) {
  rf24_.begin(ce_pin, cs_pin);
  rf24_.setAddressWidth(address_width);
  rf24_.openReadingPipe(0, address);
  rf24_.setChannel(channel);
  rf24_.setPALevel(RF24_PA_MAX);  // MIN power low rage
  rf24_.setDataRate(RF24_1MBPS);  // Minimum speed
  rf24_.startListening();         // Stop Receiving and start transmitting
  rf24_.enableDynamicPayloads();
  return true;
}

void GamepadSubscriberRf24::OnHandleData(void (GamepadSubscriber::*handle_data)(const uint8_t* data, const uint32_t length)) {
  while (rf24_.available()) {
    auto size = rf24_.getDynamicPayloadSize();
    if (size <= 0) {
      break;
    }
    uint8_t* buffer = new uint8_t[size];
    rf24_.read(buffer, size);
    (this->*handle_data)(buffer, size);
    // LOG(INFO) << "size: " << size;
    // for (uint8_t i = 0; i < size; i++) {
    //   LOG(INFO) << Log::Hex << Log::ShowBase << Log::SetWidth(4) << Log::SetFill('0') << Log::Internal << buffer[i];
    // }
    delete[] buffer;
  }
}

}  // namespace emakefun