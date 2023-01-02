#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

template <typename K, typename V>
class HashTable {
 public:
  HashTable(int size) : size_(size), table_(size) {}

  void Set(const K& key, const V& value) { table_[key % size_] = std::make_pair(key, value); }

  V Get(const K& key) { return table_[key % size_].second; }

  void Delete(const K& key) { table_[key % size_] = std::pair<K, V>(); }

  int size() const { return size_; }

  // Iterator class to allow iterating over the elements of the hash table
  class iterator {
   private:
    typename std::vector<std::pair<K, V>>::iterator it_;

   public:
    iterator(typename std::vector<std::pair<K, V>>::iterator it) : it_(it) {}

    std::pair<K, V> operator*() { return *it_; }
    iterator& operator++() { ++it_; return *this; }
    iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }
    bool operator!=(const iterator& other) { return it_ != other.it_; }
  };

  // Returns an iterator pointing to the first element of the hash table
  iterator begin() { return iterator(table_.begin()); }

  // Returns an iterator pointing to one past the last element of the hash table
  iterator end() { return iterator(table_.end()); }

 private:
  int size_;
  std::vector<std::pair<K, V>> table_;
};

#endif