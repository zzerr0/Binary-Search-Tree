#include<iostream>
using namespace std;

struct node  
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
/* newNode() allocates a new node with the given data and NULL left and  
   right pointers. */
node *newNode(int data) 
{ 
  // Allocate memory for new node  
 node *Node = new node();
  // Assign data to this node 
  Node->data = data; 
  
  // Initialize left and right children as NULL 
  Node->left = NULL; 
  Node->right = NULL; 
  return(Node); 
} 
  
  
int main() 
{ 
  /*create root*/
  node *root = newNode(1);   
  /* following is the tree after above statement  
  
        1 
      /   \ 
     NULL  NULL   
  */
    
  
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  /* 2 and 3 become left and right children of 1 
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  root->left->left  = newNode(4); 
  /* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
  cout<<root->data;
  cout<<root->left->data;  
  cout<<root->right->data;  
  cout<<root->left->left->data;  
  cout<<root->right->right->data;  
  cout<<endl;
  return 0; 
}
