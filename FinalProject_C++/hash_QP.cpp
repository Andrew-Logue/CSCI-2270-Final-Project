//Andrew Logue and Victoria (Vicky) Lopez 
//Hash Table Quadratic Probing Implementation 
#include "hash_QP.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

HTable::HTable()
{
    //constructor for the hash table of size 40009
    table_size = 40009;
    table = new HNode *[40009];

    for (int i = 0; i < table_size; i++)
    {
        table[i] = 0;
    }
}

HTable::HTable(int s)
{
    table_size = s;
    table = new HNode *[s];
    for (int i = 0; i < table_size; i++)
    {
        table[i] = 0;
    }
}

HTable::~HTable()
{
    //destructor for the hash table 
    delete[] table;
}

void HTable::insertID(int key)
{
    //create a new hash node to insert the key 
    HNode *node = new HNode(key);
    //get the index with the hash function 
    int index = HFunction(key); 
    //if the index gotten with the hash function is already taken then it enters loop to find an avaliable index
    while(table[index] != 0 && table[index]->key != key && table[index]-> key != 0)
    {
        //since the method used is quadratic probing, we had to increment and then square the index until 
        //we found an available index
        pow((index++), 2);
        //hash the new index and if it's an available index the loop breaks 
        index %= table_size;
    }
    //when the available index is found assign that spot in the table to the node we are inserting
    if(table[index] == 0 || table[index]->key == 0)
    {
        table[index] = node;
    }
}

HNode* HTable::searchID(int key)
{
    //get the index with the hash function 
    int index = HFunction(key);
    //set a counter to 0 to avoid an infinite loop 
    int counter = 0;
    //if the index found with the hash function isn't occupied return NULL
    if(table[index] == 0)
    {
       return NULL;
    }
    //if the index is occupied loop through the table
    while(table[index] != 0)
    {
        //increment the counter to exit the loop if it reaches the table size before finding the key
        if(counter++ > table_size)
        {
            //if the key isn't found return NULL
            return NULL;
        }
        //if the key at that index matches with the key we are looking for, return the node 
        if(table[index]->key == key)
        {
            return table[index];
        }
        //while going through the while loop increment the index and square it each time
        pow((index++), 2);
        //hash the index after incrementing and squaring 
        index %= table_size;
    }

    return NULL;

} 

int HTable::HFunction(int k)
{
    int hash = k;
    //divide the key value by the table size and get the reminder and use that as at potential index
    return hash % table_size;
}

void HTable::printHTable()
{
    // loop through the table and print its values 
    for(int i = 0 ; i < table_size ; i++)
    {
        if(table[i] != 0)
        {
            cout << "[" << i << "] -> ID: " << table[i]->key << " (#" << HFunction(table[i]->key) << ")" << endl;
        }
        else
        {
            // if the table is empty at a given index, print "empty"
            cout << "[" << i << "] -> Empty" << endl; 
        }
        
    }
}


