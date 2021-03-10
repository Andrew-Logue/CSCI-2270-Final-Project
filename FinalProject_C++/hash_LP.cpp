//Andrew Logue and Victoria (Vicky) Lopez
//Hash Table Linear Probing Implementation
 
#include "hash_LP.hpp"
#include <iostream>
#include <string>

using namespace std;

hashTable::hashTable()
{
    //constructor for the hash table of size 40009
    tableSize = 40009;
    table = new hashNode *[40009];

    for (int i = 0; i < tableSize; i++)
    {
        table[i] = 0;
    }
}

hashTable::hashTable(int s)
{
    tableSize = s;
    table = new hashNode *[s];
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = 0;
    }     
}

hashTable::~hashTable() 
{
    //destructor for the hash table 
    delete[] table; 
}

int hashTable::hashFunction(int k)
{
    int hash = k; 
    //divide the key value by the table size and get the reminder and use that as at potential index
    return hash % tableSize;
}

void hashTable::insert(int key)
{
    //create a new hash node to insert the key 
    hashNode *node = new hashNode(key);
    //get the index with the hash function 
    int index = hashFunction(key); 
    //if the index determined by the hash function isn't taken set the node to that index
    if(table[index] == 0)
    {
        table[index] = node;
    }
    else
    {
        //if the index gotten with the hash function is already taken then it enters loop to find an avaliable index
        while(table[index] != 0 && table[index]->key != key && table[index]-> key != 0)
        {
            //since the method used is linear probing, we had to increment the index by 1 until we found an available index
            index++;
            //hash the new index and if it's an available index the loop breaks 
            index %= tableSize;
        }
        //when the available index is found assign that spot in the table to the node we are inserting
        if(table[index] == 0 || table[index]->key == 0)
        {
            table[index] = node;
        }  
    }   
}

hashNode* hashTable::search(int key)
{
    //get the index with the hash function 
    int index = hashFunction(key);
    //set a counter to 0 to avoid an infinite loop 
    int counter = 0;

    //if the index is occupied loop through the table
    while(table[index] != 0)
    {
        //increment the counter to exit the loop if it reaches the table size before finding the key
        if(counter++ > tableSize)
        {
            //if the key isn't found return NULL
            return NULL;
        }
        //if the key at that index matches with the key we are looking for, return the node
        if(table[index]->key == key)
        {
            return table[index];
        }
        // while going through the loop increment the index by 1 each time 
        index++;
        // hash the new index 
        index %= tableSize;
    }

    //if the index found with the hash function isn't occupied, return NULL
    return NULL;
}

void hashTable::printHashTable()
{
    // loop through the table and print its values 
    for(int i = 0 ; i < tableSize ; i++)
    {
        if(table[i] != 0)
        {
            cout << "[" << i << "] -> ID: " << table[i]->key << " (#" << hashFunction(table[i]->key) << ")" << endl;
        }
        else
        {
            // if the table is empty at a given index, print "empty"
            cout << "[" << i << "] -> Empty" << endl; 
        }
        
    }
}

