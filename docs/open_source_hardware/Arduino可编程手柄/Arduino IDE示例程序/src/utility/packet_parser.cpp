#include "packet_parser.h"

#define START_CODE (0xFB)
#define PACKET_HEADER_LENGTH (7)
#define PACKET_MAX_LENGTH (20)
#define BUFFER_CAPACITY (50)

namespace {
uint16_t Checksum(const uint8_t* data, const uint8_t length) {
  uint16_t checksum = 0;
  for (uint8_t i = 0; i < length; i++) {
    checksum += data[i];
  }
  return checksum;
}
}  // namespace

PacketParser::PacketParser() : ring_buffer_(BUFFER_CAPACITY) {
}

size_t PacketParser::AppendData(const uint8_t* data, const uint8_t length) {
  return ring_buffer_.Write(data, length);
}

PacketParser::Packet* PacketParser::ReadPacket() {
  if (!Resync()) {
    return nullptr;
  }

  if (ring_buffer_.GetBytesAvailable() < PACKET_HEADER_LENGTH) {
    return nullptr;
  }

  uint8_t header[PACKET_HEADER_LENGTH] = {0};
  if (ring_buffer_.Peek(header, 0, PACKET_HEADER_LENGTH) != PACKET_HEADER_LENGTH) {
    return nullptr;
  }

  uint8_t index = 0;
  const uint8_t start_code = header[index++];
  const uint8_t packet_version = header[index++];  // reserve
  const uint8_t packet_length = header[index++];
  const uint8_t source_type = header[index++];
  const uint8_t source_address = header[index++];
  const uint16_t header_checksum = Checksum(header, index);
  uint16_t checksum = static_cast<uint16_t>(header[index++]) << 8;
  checksum |= header[index++];

  if (packet_length < PACKET_HEADER_LENGTH || packet_length > PACKET_MAX_LENGTH) {  // error length
    ring_buffer_.Skip(1);                                                           // skip start code;
    return nullptr;
  }

  const uint8_t data_length = packet_length - PACKET_HEADER_LENGTH;
  uint8_t* data = new uint8_t[data_length];
  if (ring_buffer_.Peek(data, PACKET_HEADER_LENGTH, data_length) != data_length) {
    delete[] data;
    return nullptr;
  }

  if (checksum != header_checksum + Checksum(data, data_length)) {  // error checksum
    ring_buffer_.Skip(1);                                           // skip start code;
    delete[] data;
    return nullptr;
  }

  ring_buffer_.Skip(packet_length);

  Packet* const packet = new Packet;
  packet->source_type = source_type;
  packet->source_address = source_address;
  packet->data = data;
  packet->data_length = data_length;
  return packet;
}

void PacketParser::ReleasePacket(Packet* packet) {
  if (packet != nullptr) {
    delete[] packet->data;
    delete packet;
  }
}

bool PacketParser::Resync() {
  uint8_t value = 0;
  while (ring_buffer_.Peek(&value, 0, 1) == 1) {
    if (value == START_CODE) {
      return true;
    }
    ring_buffer_.Skip(1);
  }

  return false;
}