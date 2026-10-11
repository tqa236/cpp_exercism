#pragma once

#include <cstddef>
#include <deque>
#include <stdexcept>
#include <utility>

namespace circular_buffer {

template <typename T>
class circular_buffer {
 public:
  explicit circular_buffer(std::size_t capacity) : capacity_(capacity) {}

  T read() {
    if (items_.empty()) {
      throw std::domain_error("Cannot read from an empty buffer.");
    }
    T value = std::move(items_.front());
    items_.pop_front();
    return value;
  }

  void write(const T& value) {
    if (items_.size() == capacity_) {
      throw std::domain_error("Cannot write to a full buffer.");
    }
    items_.push_back(value);
  }

  void write(T&& value) {
    if (items_.size() == capacity_) {
      throw std::domain_error("Cannot write to a full buffer.");
    }
    items_.push_back(std::move(value));
  }

  void overwrite(const T& value) {
    if (capacity_ == 0) {
      throw std::domain_error("Cannot overwrite a zero-capacity buffer.");
    }
    if (items_.size() == capacity_) {
      items_.pop_front();
    }
    items_.push_back(value);
  }

  void overwrite(T&& value) {
    if (capacity_ == 0) {
      throw std::domain_error("Cannot overwrite a zero-capacity buffer.");
    }
    if (items_.size() == capacity_) {
      items_.pop_front();
    }
    items_.push_back(std::move(value));
  }

  void clear() { items_.clear(); }

 private:
  std::size_t capacity_;
  std::deque<T> items_;
};

}  // namespace circular_buffer