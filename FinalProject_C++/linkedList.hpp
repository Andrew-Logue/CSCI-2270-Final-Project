#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include <string>

using namespace std;

struct NODE
{
    int key;
    NODE* next;
};

class LinkedList 
{
    private:
        // pointer to head of linked-list of countries
        NODE* head;

    public:
        // must have functions
        void insertID(NODE* previous, int trackerID); 
        NODE* searchID(int trackerID);
        void displayPath();

        // might be useful 
        LinkedList();
        bool isEmpty();
        void deleteID(int trackerID);
        void deleteEntireNetwork();
};


#endif