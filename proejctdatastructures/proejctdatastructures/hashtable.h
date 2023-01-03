#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

template <typename K, typename V>
class HashTable {
 public:
  struct Node {
    K key;
    V value;
    Node* next;
    Node(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
  };

  HashTable(int size) : size_(size), table_(size) {}

  void Set(const K& key, const V& value) {
    int index = Hash(key) % size_;
    Node* current = table_[index];
    while (current != nullptr) {
      if (current->key == key) {
        current->value = value;
        return;
      }
      current = current->next;
    }
    Node* new_node = new Node(key, value);
    new_node->next = table_[index];
    table_[index] = new_node;
  }

  V Get(const K& key) {
    int index = Hash(key) % size_;
    Node* current = table_[index];
    while (current != nullptr) {
      if (current->key == key) {
        return current->value;
      }
      current = current->next;
    }
    throw std::out_of_range("Key not found");
  }

  void Delete(const K& key) {
    int index = Hash(key) % size_;
    Node* current = table_[index];
    if (current == nullptr) {
      return;
    }
    if (current->key == key) {
      table_[index] = current->next;
      delete current;
      return;
    }
    while (current->next != nullptr) {
      if (current->next->key == key) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return;
      }
      current = current->next;
    }
  }

  int size() const { return size_; }

  // Iterator class to allow iterating over the elements of the hash table
  class iterator {
   private:
    Node* current_;

   public:
    iterator(Node* current) : current_(current) {}

    std::pair<K, V> operator*() { return {current_->key, current_->value}; }
    iterator& operator++() {
      current_ = current_->next;
      return *this;
    }
    iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }
    bool operator!=(const iterator& other) { return current_ != other.current_; }
  };

  // Returns an iterator pointing to the first element of the hash table
  iterator begin() { return iterator(table_.begin()); }

  // Returns an iterator pointing to one past the last element of the hash table
  iterator end() { return iterator(nullptr); }

 private:
  int size_;
  std::vector<Node*> table_;

  // Hash function to determine the index at which a key should be stored
  size_t Hash(const K& key) {
  std::hash<K> hasher;
  size_t hash_value = hasher(key);
  return hash_value % size_;
}
};

#endif
