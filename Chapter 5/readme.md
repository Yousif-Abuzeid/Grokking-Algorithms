# Hash Tables

## Definition

A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

## Hash Function

A hash function is any function that can be used to map data of arbitrary size to fixed-size values. The values returned by a hash function are called hash values, hash codes, digests, or simply hashes. The values are used to index a fixed-size table called a hash table. Use of a hash function to index a hash table is called hashing or scatter storage addressing.

## Use Cases

- Phone Book
- address to ip mapping
- etc

## Collision

A collision occurs when two or more keys are hashed to the same index in the hash table. There are several ways to handle collisions:

- Separate Chaining
- Open Addressing

## Time Complexity


| Operation | Average | Worst Case |
| --------- | ------- | ---------- |
| Search    | O(1)    | O(n)       |
| Insert    | O(1)    | O(n)       |
| Delete    | O(1)    | O(n)       |

## Space Complexity

O(n)

