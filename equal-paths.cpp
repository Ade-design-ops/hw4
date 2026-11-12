#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
static int leafDept(Node* node)
{
  if(node->left == nullptr && node->right == nullptr){
    return 0;
  }
  if (node->left == nullptr){
    int r = leafDept(node->right);
    if(r == -1){
      return -1;
    }else {
      return r + 1;
    }
  }
  if (node->right == nullptr){
    int l = leafDept(node->left);
    if(l == -1){
      return -1;
    }else {
      return l + 1;
    }
  }

  int l = leafDept(node->left);
  int r = leafDept(node->right);
  if(l == -1 || r == -1 || l!= r){
    return -1;
  }
  return l + 1;
  
}

bool equalPaths(Node * root)
{
    // Add your code below
    if (root == nullptr){
      return true;
    }
    return leafDept(root) != -1;

}

