#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

template <typename K, typename V>
class HashTable
{
public:
HashTable(int size);
void Set(const K& key, const V& value);
V Get(const K& key);
void Delete(const K& key);

private:
std::vector<std::pair<K, V>> table_;
int size_;
};

#endif