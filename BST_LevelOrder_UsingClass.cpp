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
  void levelorder(node*);
  void lshow();
   
   void print(node *Node){
        if(Node == NULL){
            return;
        }
        cout<<Node->data<<" ";
        print(Node->left);
        print(Node->right);
    }
    void jprint(){
        print(root);
        }
  
};

void bt::jinsert(int data)
  {
    insert(root, data);
  }
//inserting elements into the BST tree  
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
//  LEVEL ORDER FUNCTION
void bt::levelorder(node *root)
{
 if(root==NULL) 
 return;
 queue<node*>q;
 q.push(root);
 //while there is at least one item
 while(!q.empty())
 {
   node *curr=q.front();
   q.pop();
   cout<<curr->data<<" ";
   if(curr->left!=NULL)
   q.push(curr->left);
   if(curr-> right!=NULL)
   q.push(curr->right);
 }
}
void bt::lshow()
{
  levelorder(root);
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
  obj.jprint();
  cout<<endl;
  obj.lshow();
  cout<<endl;
}
    
