#ifndef HASH_LP_HPP
#define HASH_LP_HPP

#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

struct hashNode
{
  int key;

  hashNode()
  {
    key = 0;
  }
  hashNode(int k)
  {
    key = k;
  }
  ~hashNode() {}
};

class hashTable
{
    hashNode **table; 
    int tableSize = 40009;

  public:
    hashTable();
    hashTable(int s);
    ~hashTable();
    void insert(int key);
    hashNode *search(int key);
    int hashFunction(int k);
    void printHashTable();

}; 

#endif