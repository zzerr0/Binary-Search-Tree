//creating a binary tree

#include <iostream>
using namespace std;

class node{
  public:
    node *left, *right;
    int data;    
};
      /*             1 
                    / \ 
                   2     3 
                  / \    /  \ 
               NULL NULL NULL NULL 
        */

class bt{
  public:
   node *root = NULL;
   void insert( int );
   void display(); 
};

void bt :: insert( int d ){
  root = new node();
  root->data = d;
  root->left = 50;
  root->right = 60;
  root->left->left = 100;
  root->right->right = 200;
  
}

void bt :: display(){
  cout<<"root->"<<root->data;
  cout<<"root->left"<<root->left->data;
}
        
int main()
{
  //creating the root node
  bt o;
  o.insert(10);
  o.display();
}
