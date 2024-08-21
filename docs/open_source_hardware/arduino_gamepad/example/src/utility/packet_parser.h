#pragma once

#include "ring_buffer.h"

class PacketParser {
 public:
  struct Packet {
    uint8_t source_type;
    uint8_t source_address;
    uint8_t* data;
    uint8_t data_length;
  };

  PacketParser();

  size_t AppendData(const uint8_t* data, const uint8_t length);

  Packet* ReadPacket();

  void ReleasePacket(Packet* packet);

 private:
  bool Resync();

  RingBuffer ring_buffer_;
};