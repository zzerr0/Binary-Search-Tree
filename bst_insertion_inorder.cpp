#include<iostream>
using namespace std; 

struct node
{
  node *left, *right;
  int data;
};
node *create(int d)
 {
   node *newnode=new node();
   newnode->data=d;
   newnode->left=newnode->right=NULL;
   return newnode;
 }


node *insert(node *root,int d)
{
  if(root==NULL)
  {
    root=create(d);
  }
  else
  if(d<=root->data)
  {
    root->left=insert(root->left,d);
  }
  else 
  {
    root->right=insert(root->right,d);
  }
  return root;
}


 
 
 void inorder(node *root)  
{  
    if (root == NULL)  
        return;  
  
    inorder(root->left);  
    cout<< root->data << "   ";  
    inorder(root->right);  
} 

int main()
{
  node *root=NULL;
  int val[5];
  for(int i=0;i<5;i++)
  {
    cin>>val[i];
    cout<<endl;
    root=insert(root,val[i]);
  }
  
  inorder(root);
  return 0;
}
