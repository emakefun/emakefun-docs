#include "gamepad_subscriber_ble.h"

namespace emakefun {
GamepadSubscriberBle::GamepadSubscriberBle() = default;

bool GamepadSubscriberBle::Initialize(Stream& stream) {
  stream_ = &stream;
  return true;
}

void GamepadSubscriberBle::OnHandleData(void (GamepadSubscriber::*handle_data)(const uint8_t* data, const uint32_t length)) {
  if (stream_ == nullptr) {
    return;
  }
  const auto length = stream_->available();
  if (length > 0) {
    uint8_t* buffer = new uint8_t[length];
    stream_->readBytes(buffer, length);
    (this->*handle_data)(buffer, length);
    // LOG(INFO) << "size: " << size;
    // for (uint8_t i = 0; i < size; i++) {
    //   LOG(INFO) << Log::Hex << Log::ShowBase << Log::SetWidth(4) << Log::SetFill('0') << Log::Internal << buffer[i];
    // }
    delete[] buffer;
  }
}

}  // namespace emakefun