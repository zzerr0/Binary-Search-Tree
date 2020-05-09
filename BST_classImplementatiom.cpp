#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node *left;
  node *right;
  //paramterized constructor for Intializing
  //intial tree node
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
  //passing node value as pointer to reference 
  //so that we dont have to return node value
  void insert(node*&,int);
  void jinsert(int);
  
};


void bt::jinsert(int data)
  {
    insert(root, data);
  }
void bt::insert(node *&nodeleaf, int d)
  {
    if(nodeleaf==NULL)
    {
      nodeleaf=new node(d);
    }
    if(d<nodeleaf->data)
    {
     insert(nodeleaf->left,d);
    }
    else 
    if(d>nodeleaf->data)
    {
      insert(nodeleaf->right, d);
    }
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
}
