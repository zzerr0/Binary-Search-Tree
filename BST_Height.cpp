#include<iostream>
#include<queue>
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
  int height(node*);
  void callheight();
 
  
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
 
//FINDING HEIGHT OF TREE 
/*
°Height Of Tree = no. of edges in longest path from
root to leaf node 

°Depth Of Node = No. of edges from root to that node

°Height Of Node = No. of edges from that node to 
leaf node 
Height Of Tree Can Be Found By Two Methods 
-Recursive Method 
-Iterative Method 
In this program we'll do with iterative method
*/
//we'll be counting height as no. of nodes from 
//root to leafnode
void bt:: callheight() 
{
  height(root);
}
int bt::height(node *root)
{
  if(root==NULL)
  return 0;
  
  queue<node*> q;
  q.push(root);
  //put hyt = -1 if you want to neglect the root node
  //else put hyt=0 to start counting fronm the root node
  int hyt =0;
  
  
  //while queue is not empty 
  while(!q.empty()) //or you can use while(1)
  {
    //no. of nodes in queue
    int nodecount= q.size();
    if(nodecount==0)
    //we've used break so that we can exit loop
    //when there's no element in the queue
    break;
    
    hyt++;
    while(nodecount>0)
    { 
/* we use curr = q.front() because we'll pop the
   the front element and front address will be lost
   therefore we store it into another variable  
 */   
      node *curr=q.front();
     //q.pop() removes the first element from queue
      q.pop();
     
     //it pushse the left subtree data into the queue
      if(curr->left!=NULL)
      q.push(curr->left);
    //it pushes the right subtree data into the queue  
      if(curr->right!=NULL)
      q.push(curr->right);   
      nodecount--; 
    }
  }
  cout<<hyt;
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
  cout<<"\n Height of tree is ";
  obj.callheight();
  cout<<endl;
  
}
