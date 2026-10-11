#pragma once

#include <cstddef>
#include <iterator>
#include <memory>
#include <vector>

namespace binary_tree {

template <typename T>
class binary_tree {
 public:
  explicit binary_tree(const T& value) : data_(value) {}

  const T& data() const { return data_; }

  const std::unique_ptr<binary_tree>& left() const { return left_; }
  const std::unique_ptr<binary_tree>& right() const { return right_; }

  void insert(const T& value) {
    std::unique_ptr<binary_tree>& child = value <= data_ ? left_ : right_;
    if (child) {
      child->insert(value);
    } else {
      child.reset(new binary_tree(value));
    }
  }

  class const_iterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

    const_iterator() = default;
    explicit const_iterator(const binary_tree* root) { descend_left(root); }

    reference operator*() const { return stack_.back()->data_; }
    pointer operator->() const { return &stack_.back()->data_; }

    const_iterator& operator++() {
      const binary_tree* node = stack_.back();
      stack_.pop_back();
      descend_left(node->right_.get());
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator copy = *this;
      ++(*this);
      return copy;
    }

    bool operator==(const const_iterator& other) const {
      if (stack_.empty() || other.stack_.empty()) {
        return stack_.empty() == other.stack_.empty();
      }
      return stack_.back() == other.stack_.back();
    }

    bool operator!=(const const_iterator& other) const {
      return !(*this == other);
    }

   private:
    void descend_left(const binary_tree* node) {
      while (node) {
        stack_.push_back(node);
        node = node->left_.get();
      }
    }

    std::vector<const binary_tree*> stack_;
  };

  const_iterator begin() const { return const_iterator(this); }
  const_iterator end() const { return const_iterator(); }

 private:
  T data_;
  std::unique_ptr<binary_tree> left_;
  std::unique_ptr<binary_tree> right_;
};

}  // namespace binary_tree