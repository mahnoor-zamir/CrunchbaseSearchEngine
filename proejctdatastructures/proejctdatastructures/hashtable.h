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

	std::vector<std::pair<K, V>> table_;
	int size_;
};

template <typename K, typename V>
HashTable<K, V>::HashTable(int size) : size_(size)
{
    table_.resize(size);
}

template <typename K, typename V>
void HashTable<K, V>::Set(const K& key, const V& value)
{
    int index = key % size_;
    table_[index] = std::make_pair(key, value);
}

template <typename K, typename V>
V HashTable<K, V>::Get(const K& key)
{
    int index = key % size_;
    return table_[index].second;
}

template <typename K, typename V>
void HashTable<K, V>::Delete(const K& key)
{
    int index = key % size_;
    table_[index] = std::make_pair(K(), V());
}

#endif