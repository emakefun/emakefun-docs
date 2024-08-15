#pragma once

#include <stddef.h>
#include <stdint.h>

class RingBuffer {
 public:
  explicit RingBuffer(const size_t size);

  virtual ~RingBuffer();

  void Reset();

  size_t Read(uint8_t* const buffer, size_t length);

  size_t Write(const uint8_t* const data, size_t length);

  size_t Peek(uint8_t* const buffer, const size_t skip_length, size_t length);

  size_t Skip(size_t length);

  bool IsEmpty();

  bool IsFull();

  size_t GetBytesAvailable();

  size_t GetSpaceAvailable();

 private:
  RingBuffer(const RingBuffer&) = delete;
  RingBuffer& operator=(const RingBuffer&) = delete;

  const size_t capacity_;
  uint8_t* const buffer_ = nullptr;
  size_t write_position_ = 0;
  size_t read_position_ = 0;
};