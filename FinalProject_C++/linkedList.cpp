//Andrew Logue and Victoria (Vicky) Lopez
//Linked List implementation
#include "linkedList.hpp"
#include <iostream>
#include <string>

using namespace std; 

//constructor
LinkedList::LinkedList()
{
    head = NULL;
}

//insert function

void LinkedList::insertID(NODE* previous, int trackerID)
{
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        head = new NODE;
        head->key = trackerID;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL)
    {
        NODE *new_node = new NODE;
        new_node->key = trackerID;
        new_node->next = head;
        head = new_node;
    }
    else
    {
        NODE *new_node = new NODE;
        new_node->key = trackerID;
        new_node->next = previous->next;
        previous->next = new_node;
    }
}



// search tracker ID function
NODE* LinkedList::searchID(int trackerID)
{
    NODE* pres = head; 

    while(pres != NULL && pres->key != trackerID)
    {
        pres = pres->next;
        
    }

    return pres;
}

// display linked list function
void LinkedList::displayPath()
{
    NODE* printer = head; 

    cout << "== CURRENT PATH ==" << endl; 

    if(printer == NULL)
    {
        cout << "nothing in path" << endl; 
    }
    else {
        while(printer->next != NULL) {
            cout << printer->key << " -> " << endl; 
            printer = printer->next;
    
        }
        cout << printer->key << " -> ";
        cout << "NULL" << endl;
    }

    cout << "===" << endl; 
}


