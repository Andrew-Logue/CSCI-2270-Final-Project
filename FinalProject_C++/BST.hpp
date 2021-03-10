#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int key;
    Node* left = NULL;
    Node* right = NULL;

    Node(int trackerID) 
    {
        key = trackerID;
    }
};

class BST
{
    private:
    //pointer to the root of the Binary Search Tree
      Node *root;

    public:
      //constructor
      BST();
      //destructor
      ~BST();
      
      //must have functions 
      void insertID(int trackerID);
      void printInventory(Node* root);
      Node* searchTrackingID(int trackerID);

      //might be useful
      void inorderTraversal();
      void deleteID(int trackerID);
      void leftRotation(Node* curr);

};

#endif