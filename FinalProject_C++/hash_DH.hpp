//extra credit double hashing
#include <iostream>
#include <bits/stdc++.h> 

//declare ash table size
#define TABLE_SIZE 40009 
//to be used in second hash function
#define PRIME 20005 

using namespace std; 
  
class DoubleHash { 
    //create pointer to array containing buckets 
    int* hashTable; 
    //current size of hash table
    int curr_size; 
  
public: 
    //check if hash table is full 
    bool isFull(); 
    
    //get first hash 
    int hash1(int key); 
  
    //get second hash 
    int hash2(int key);
  
    DoubleHash(); 
  
    //insert key into hash table 
    void insertDH(int key);
  
    //search for key in hash table 
    void searchDH(int key);
    
    //display hash table 
    void displayHash();
    
}; 