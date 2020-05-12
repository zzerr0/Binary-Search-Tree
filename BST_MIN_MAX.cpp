//Minimum Element In Binary Search Tree 
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
    void ino(node*);
    void min(node*);
    void max(node*);
    
};

void bt::jinsert(int d)
{
  insert(root, d);
}
void bt::insert(node *&parent, int d)
{
  if(parent==NULL)
  {
    parent=new node(d);
  }
  if(d<parent->data)
  {
    insert(parent->left, d);
  }
  else
  if(d>parent->data)
  {
    insert(parent->right, d);
  }
}

void bt::traverse()
{
  min(root);
  cout<<endl;
  cout<<"\n In order Traversal "<<endl;
  ino(root);
   max(root);
}

void bt::ino(node *parent)
{
  
  if(parent==NULL)
  {
    return;
  }
  
  else
  {
    
  ino(parent->left);
  cout<<parent->data<<endl;
  ino(parent->right);
  }
  
}

void bt::min(node *root)
{
  if(root==NULL)
  {
    cout<<"\n Tree is Empty please enter some values";
    cout<<endl;
  } 
  node *cur=root;
  while(cur->left!=NULL)
  {
    cur=cur->left;
  }
  cout<<"\n Minimum element is "<<cur->data<<endl;
}

void bt::max(node *root)
{
  if(root==NULL)
  {
    cout<<"\n Tree is Empty please enter some values";
    cout<<endl;
  } 
  node *cur=root;
  while(cur->right!=NULL)
  {
    cur=cur->right;
  }
  cout<<"\n Maximum element is "<<cur->data<<endl;
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
