/**
 * @file HashTable.hpp
 * @brief Implementation of a hash table with universal and division hash functions.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "LinkedList.hpp"

namespace myDataStructures {

    /**
     * @brief Universal hash function for generic keys.
     * 
     * Computes the hash value of a key using the formula:
     * h_ab(k) = ((a * k + b) % p) % m
     * 
     * @tparam K Type of the key (should be integral type).
     * @param key The key to be hashed.
     * @param m The size of the hash table.
     * @param p A prime number used in hashing.
     * @param a A random number from [1, p-1].
     * @param b A random number from [0, p-1].
     * @return int The resulting hash value.
     */
    template <typename K>
    int universalHash(const K& key, int m, int p, int a, int b) {
        int hashValue = 0;
        hashValue = ((a * key + b) % p) % m;
        return hashValue % m;
    }

    /**
     * @brief Universal hash function specialized for strings.
     * 
     * Computes the hash value of a string key.
     * 
     * @param key The string to be hashed.
     * @param m The size of the hash table.
     * @param p A prime number used in hashing.
     * @param a A random number from [1, p-1].
     * @param b A random number from [0, p-1].
     * @return int The resulting hash value.
     */
    int universalHash(const std::string& key, int m, int p, int a, int b) {
        int hashValue = 0;
        for (char c : key) {
            hashValue = (hashValue * a + c) % p;
        }
        return hashValue % m;
    }

    /**
     * @brief A hash table class template using linked lists for collision handling.
     * 
     * The hash table is templated on both key (K) and value (Val) types. It uses
     * a universal hash function to map keys to table indices.
     * 
     * @tparam K The type of the keys in the hash table.
     * @tparam Val The type of the values associated with the keys.
     */
    template<typename K, typename Val>
    class HashTable {
    private:
        std::vector<myDataStructures::LinkedList<std::pair<K, Val>>> Table; ///< Internal storage using linked lists.
        int size;      ///< Current number of elements in the hash table.
        int capacity;  ///< Maximum capacity of the hash table.
        int a;         ///< Random number a from [1, p-1].
        int b;         ///< Random number b from [0, p-1].
        const int p = 100;  ///< Prime number used for hashing.

    public:
        /**
         * @brief Default constructor.
         * Initializes the hash table with a default capacity of 10.
         */
        HashTable() : size(0), capacity(10) {
            a = rand() % (p - 1) + 1;
            b = rand() % p;
            Table.resize(capacity);
        }

        /**
         * @brief Parameterized constructor.
         * Initializes the hash table with a specified capacity.
         * 
         * @param capacity The initial capacity of the hash table.
         */
        HashTable(int capacity) : size(0), capacity(capacity) {
            Table.resize(capacity);
            a = rand() % (p - 1) + 1;
            b = rand() % p;
        }

        /**
         * @brief Inserts a key-value pair into the hash table.
         * 
         * @param key The key to be inserted.
         * @param value The value associated with the key.
         */
        void insert(const K& key, const Val& value) {
            int index = universalHash(key, capacity, p, a, b);
            Table[index].insert(std::make_pair(key, value));
            size++;
        }

        /**
         * @brief Removes a key-value pair from the hash table.
         * 
         * @param key The key to be removed.
         */
        void remove(const K& key) {
            int index = universalHash(key, capacity, p, a, b);
            auto& list = Table[index];
            for (int i = 0; i < list.size(); i++) {
                if (list[i].first == key) {
                    list.remove(i);
                    size--;
                    return;
                }
            }
        }

        /**
         * @brief Overloaded subscript operator to access the value associated with a key.
         * 
         * @param key The key whose value is to be accessed.
         * @return Val& Reference to the value associated with the key.
         * @throws std::out_of_range if the key is not found.
         */
        Val& operator[](const K& key) {
            int index = universalHash(key, capacity, p, a, b);
            auto& list = Table[index];
            for (int i = 0; i < list.size(); i++) {
                if (list[i].first == key) {
                    return list[i].second;
                }
            }
            throw std::out_of_range("Key not found");
        }

        /**
         * @brief Checks if the hash table contains a key.
         * 
         * @param key The key to check.
         * @return true if the key is present, false otherwise.
         */
        bool contains(const K& key) {
            int index = universalHash(key, capacity, p, a, b);
            auto& list = Table[index];
            for (int i = 0; i < list.size(); i++) {
                if (list[i].first == key) {
                    return true;
                }
            }
            return false;
        }

        /**
         * @brief Gets the number of elements in the hash table.
         * 
         * @return int The current number of elements in the hash table.
         */
        int getSize() const {
            return size;
        }

        /**
         * @brief Gets the capacity of the hash table.
         * 
         * @return int The capacity of the hash table.
         */
        int getCapacity() const {
            return capacity;
        }

        /**
         * @brief Overloaded stream insertion operator for printing the hash table.
         * 
         * @param os The output stream.
         * @param hashTable The hash table to print.
         * @return std::ostream& The output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {
            for (int i = 0; i < hashTable.capacity; i++) {
                os << "[" << i << "] : ";
                auto& list = hashTable.Table[i];
                for (int j = 0; j < list.size(); j++) {
                    os << "(" << list[j].first << "," << list[j].second << ") ";
                }
                os << std::endl;
            }
            return os;
        }
    };

}
