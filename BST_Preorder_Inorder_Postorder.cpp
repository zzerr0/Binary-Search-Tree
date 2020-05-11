#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node *left;
  node *right;
  node(int x)
  {
    data=x;
    left=NULL;
    right=NULL;
  }  
};

class bt
{
  public:
  node *root=NULL;
  void jinsert(int);
  void insert(node*&,int);
  void traverse();
  void preo(node*);
  void ino(node*);
  void posto(node*);
};
void bt::jinsert(int d)
{
  insert(root, d);
}
void bt::insert(node *&newnode, int d)
 {
  if(newnode==NULL) 
  {
    newnode=new node(d);
  }
  if(d<newnode->data)
  {
    insert(newnode->left,d);
  }
  else 
  if(d>newnode->data)
  {
    insert(newnode->right,d);
  }
  }
void bt::traverse()
{
  /* 
  Preorder Traversal:

  Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., 
      call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., 
      call Preorder(right-subtree) 
  */
  cout<<"PreOrder "<<endl;
  preo(root);
  cout<<endl;
  
  /*
   Inorder Traversal:

   Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e.,
      call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e.,
      call Inorder(right-subtree)
  */
  cout<<"InOrder "<<endl;
  ino(root);
  cout<<endl;
  
  /*
   Postorder Traversal:

   Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e.,
      call Postorder(left-subtree)
   2. Traverse the right subtree, i.e.,
      call Postorder(right-subtree)
   3. Visit the root.
  */
  cout<<"PostOrder "<<endl;
  posto(root);
  cout<<endl;
}
void bt::preo(node *root)
{
  if(root==NULL)
  return;
  else
  cout<<root->data<<endl;
  preo(root->left);
  preo(root->right);
}

void bt::ino(node *root)
{
  if(root==NULL)
  return;
  else
  ino(root->left);
  cout<<root->data<<endl;
  ino(root->right);
}

void bt::posto(node *root)
{
  if(root==NULL)
  return;
  else
  posto(root->left);
  posto(root->right);
  cout<<root->data<<endl;
}


int main()
{
  bt obj;
  int n, val;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>val;
    obj.jinsert(val);
  }
  obj.traverse();
return 0;
}
