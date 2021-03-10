// Andrew Logue and Victoria (Vicky) Lopez 
// Hash Table Chaining Implementation 
#include "hash_C.hpp"
#include <iostream>
#include <string>

using namespace std;

HashTable::HashTable()
{
  //constructor for the hash table of size 40009
  tableSize = 40009;
  table = new HashNode *[40009];

  for(int i = 0 ; i < tableSize ; i++)
  {
    table[i] = 0;
  }
}

HashTable::HashTable(int bsize)
{
    table = new HashNode *[bsize];

    for(int i = 0 ; i < bsize; i++)
    {
        table[i] = 0;
    }

}

bool HashTable::insertItem(int key) 
{ 
    //get the index with the hash function
    int index = hashFunction(key); 
    //create a new hash node to insert the key 
    HashNode* new_node = new HashNode(key);
    // check if the index is less than the table size
    if(index <= tableSize)
    {
      //if the spot at that index is available set the node to that index
      if (table[index] == 0)
      {
        table[index] = new_node;
      }  
      //if the spot at that index is unavailable set the new node to next one 
      //implementing a linked list
      else 
      {
        new_node->next = table[index];
        table[index] = new_node;
      }
      //return true if the insertion was succesful 
      return true;
    }
    else
    {
      return false;
    }
    
}

  HashNode* HashTable::searchItem(int key) 
  {
    //get the index with the hash function
    int index = hashFunction(key);
    //if the spot at that index is empty return 0
    if (table[index] == 0)
    {
      return 0;
    }  
    else 
    {
      //create a temp node and set it to the value at that index
      HashNode* curr = table[index];
      //loop through the table like you would with a linked list 
      while (curr != 0) 
      {
        //when the key of that temp node matches with the key we are trying to find return the temp node 
        if (curr->key == key)
        {
          return curr;
        } 
        // keep moving through the linked list until the key matches
        else
        {
          curr = curr->next;
        } 
      }
      return 0;
    }
  }


unsigned int HashTable::hashFunction(int key) 
{
  int hash = key;
   //divide the key value by the table size and get the reminder and use that as at potential index   
  return hash % 40009;
}


void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) 
    {
      if (table[i] != 0) 
      {
          cout << "[" << i << "] ";
          //create a temp node to loop through the list and print its key values  
          HashNode* curr = table[i];
          while (curr != 0) 
          {
            cout << "-> ID: " << curr->key << " (#" << hashFunction(curr->key) << ")" << endl; 	  
            curr = curr->next;
          }
          cout << endl;
      }
      else 
      {
        cout << "[" << i << "] -> Empty" << endl;
      }
    }

}

