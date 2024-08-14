#include "ring_buffer.h"

#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

RingBuffer::RingBuffer(const size_t size) : capacity_(size), buffer_(new uint8_t[size]) {
}

RingBuffer::~RingBuffer() {
  delete[] buffer_;
}

void RingBuffer::Reset() {
  write_position_ = read_position_ = 0;
}

size_t RingBuffer::Read(uint8_t* const buffer, size_t length) {
  length = MIN(GetBytesAvailable(), length);
  const auto first_length = MIN(length, capacity_ - read_position_);
  memcpy(buffer, buffer_ + read_position_, first_length);

  if (first_length < length) {
    memcpy(buffer + first_length, buffer_, length - first_length);
  }

  read_position_ = (length + read_position_) % capacity_;

  return length;
}

size_t RingBuffer::Write(const uint8_t* const data, size_t length) {
  length = MIN(GetSpaceAvailable(), length);
  const auto first_length = MIN(length, capacity_ - write_position_);
  memcpy(buffer_ + write_position_, data, first_length);

  if (first_length < length) {
    memcpy(buffer_, data + first_length, length - first_length);
  }

  write_position_ = (length + write_position_) % capacity_;
  return length;
}

size_t RingBuffer::Peek(uint8_t* const buffer, const size_t skip_length, size_t length) {
  if (GetBytesAvailable() < skip_length) {
    return 0;
  }

  length = MIN(GetBytesAvailable() - skip_length, length);
  const size_t read_position = (read_position_ + skip_length) % capacity_;
  const auto first_length = MIN(length, capacity_ - read_position);
  memcpy(buffer, buffer_ + read_position, first_length);
  if (first_length < length) {
    memcpy(buffer + first_length, buffer_, length - first_length);
  }
  return length;
}

size_t RingBuffer::Skip(size_t length) {
  length = MIN(GetBytesAvailable(), length);
  read_position_ = (length + read_position_) % capacity_;
  return length;
}

bool RingBuffer::IsEmpty() {
  return read_position_ == write_position_;
}

bool RingBuffer::IsFull() {
  return GetSpaceAvailable() == 0;
}

size_t RingBuffer::GetBytesAvailable() {
  return write_position_ >= read_position_ ? write_position_ - read_position_ : capacity_ - read_position_ + write_position_;
}

size_t RingBuffer::GetSpaceAvailable() {
  return read_position_ > write_position_ ? read_position_ - write_position_ - 1
                                          : capacity_ - write_position_ + read_position_ - 1;
}