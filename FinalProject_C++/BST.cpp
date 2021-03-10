//Andrew Logue and Victoria (Vicky) Lopez
//BST implementation;
#include "BST.hpp"
#include <iostream>
#include <string>

using namespace std; 

BST::BST() 
{
  root = NULL;
}

BST::~BST() 
{
  root = NULL;
}

//helper function for the insert function 
Node* insertHelper(Node* node, int trackerID) 
{
    if(node == NULL) 
    {
        Node* temp = new Node(trackerID);
          return temp;
    }
    else if(node->key < trackerID) 
    {
        node->right = insertHelper(node->right, trackerID);
    }
    else 
    {
        node->left = insertHelper(node->left, trackerID);
    }
    return node;
}

void BST::insertID(int trackerID) 
{
  root = insertHelper(root, trackerID);

}

//helper function for the search function 
Node* searchHelper(Node* root, int trackerID) 
{
  Node* temp = root;

    if(temp == NULL) 
    {
    return NULL;
    }
    else 
    {
        if(trackerID == temp->key) 
        {
          return temp;
        }
        else 
        {
          if(trackerID < temp->key) 
          {
            //when the ID is less than the previous call the function with the left child 
            temp = searchHelper(temp->left, trackerID);
          }
          else if(trackerID > temp->key) 
          {
            //when the ID is less than the previous call the function with the right child
            temp = searchHelper(temp->right, trackerID);
          }
      }
      return temp;
    }
}

Node* BST::searchTrackingID(int trackerID) 
{
  Node* temp = searchHelper(root, trackerID);

  //trackerID found
  if (temp != NULL) {
    return temp;

  }
  //trackerID not found
  else {
    cout << "TrackerID not found" << endl;
    return temp;

  }

}

void BST::printInventory(Node* node)
{
  if(node->left != NULL)
  {
    printInventory(node->left);
  }

  cout << "Tracker ID: " << node->key << " " << node->key << endl;

  if (node->right != NULL)
  {
    printInventory(node->right);
  }

}

