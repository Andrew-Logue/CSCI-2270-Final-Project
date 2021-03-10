#ifndef HASH_C_HPP
#define HASH_C_HPP

#include <string>

using namespace std;

struct HashNode
{
    int key; 
    struct HashNode* next;

    HashNode()
    {
        key = 0;
        next = 0;
    }

    HashNode(int k)
    {
        key = k; 
        next = 0;
    }


    ~HashNode(); 
};

class HashTable
{
    //set table size to 40009
    int tableSize = 40009;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    HashNode* *table;
    int numOfcolision;

    
    HashNode* createNode(int key, HashNode* next);

public:

    HashTable();

    HashTable(int bsize);  // Constructor

    ~HashTable();

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    HashNode* searchItem(int key);
};

#endif

