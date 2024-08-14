#pragma once

namespace emakefun {
template <typename T>
class List {
 public:
  struct Node {
    Node(const T& data) : data(data) {
    }
    Node* next = nullptr;
    T data;
  };

  struct Iterator {
    Iterator(Node* node) : node(node) {
    }

    Iterator& operator++() {
      if (node != nullptr) {
        node = node->next;
      }
      return *this;
    }

    T& operator*() const {
      return node->data;
    }

    bool operator!=(const Iterator& other) const {
      return node != other.node;
    }
    Node* node;
  };

  void PushBack(const T& data) {
    auto* const node = new Node(data);

    if (head_ == nullptr) {
      head_ = node;
    } else {
      tail_->next = node;
    }
    tail_ = node;
  }

  const Iterator begin() {
    return Iterator(head_);
  }

  const Iterator end() {
    return Iterator(nullptr);
  }

 private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};
}  // namespace emakefun