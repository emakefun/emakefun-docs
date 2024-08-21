#pragma once

#include "gamepad_model.h"
#include "utility/packet_parser.h"

namespace emakefun {
class GamepadSubscriber {
 public:
  virtual ~GamepadSubscriber() = default;
  void AttachModel(GamepadModel* const model);
  virtual void Tick();

 protected:
  virtual void OnHandleData(void (GamepadSubscriber::*handle_data)(const uint8_t* data, const uint32_t length)) = 0;

 private:
  void HandleData(const uint8_t* data, const uint32_t length);
  void HandlePacket();
  void HandlePacket(PacketParser::Packet* packet);

 private:
  GamepadModel* model_ = nullptr;
  PacketParser packet_parser_;
};
}  // namespace emakefun