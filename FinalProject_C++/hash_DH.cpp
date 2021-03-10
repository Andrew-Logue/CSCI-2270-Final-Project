//Andrew Logue and Victoria (Vicky) Lopez

#include "hash_DH.hpp"
#include <bits/stdc++.h> 


using namespace std;

bool DoubleHash::isFull() 
{ 
  
    //checks if hash size reaches maximum size 
    return (curr_size == TABLE_SIZE); 
} 

int DoubleHash::hash1(int key) 
{ 
    return (key % TABLE_SIZE); 
} 
  
int DoubleHash::hash2(int key) 
{ 
    return (PRIME - (key % PRIME)); 
} 

DoubleHash::DoubleHash() 
{ 
    //constructor for the table of size 40009
    hashTable = new int[TABLE_SIZE]; 
    curr_size = 0; 
    for (int i = 0; i < TABLE_SIZE; i++) 
        hashTable[i] = -1; 
}

void DoubleHash::insertDH(int key)
{
    // check if hash table is full 
        if (isFull()) 
            return; 
  
        // get index from first hash 
        int index = hash1(key); 
  
        // if collision occurs 
        if (hashTable[index] != -1) 
        { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) 
            { 
                // get newIndex 
                int newIndex = (index + i * index2) % TABLE_SIZE; 
  
                // if no collision occurs, store the key 
                if (hashTable[newIndex] == -1) 
                { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
  
        // if no collision occurs 
        else
            hashTable[index] = key; 
        curr_size++; 
}

void DoubleHash::searchDH(int key)
{
    int index1 = hash1(key); 
        int index2 = hash2(key); 
        int i = 0; 
        while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key) 
        { 
            if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1) 
            { 
                cout << key << " does not exist" << endl; 
                return; 
            } 
            i++; 
        }
}

void DoubleHash::displayHash() 
{
    for (int i = 0; i < TABLE_SIZE; i++) { 
            if (hashTable[i] != -1) 
                cout << i << " --> "
                     << hashTable[i] << endl; 
            else
                cout << i << endl; 
        } 
}

