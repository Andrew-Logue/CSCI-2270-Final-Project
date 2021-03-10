// hash table QUADRATIC probing
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

struct HNode
{
  
  int key;

  HNode()
  {
    key = 0;
  }
  HNode(int k)
  {
    key = k;
  }
  ~HNode() {}
};

class HTable
{
    HNode **table; 
    int table_size = 40009;

  public:
    HTable();
    HTable(int s);
    ~HTable();
    void insertID(int key);
    HNode* searchID(int key);
    int HFunction(int k);
    void printHTable();

};