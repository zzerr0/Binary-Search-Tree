#include <iostream>
#define SPACE 10

using namespace std;

class Tnode{
  public:
    int data;
    Tnode *left, *right;
    
    //DEFAULT CONSTRUCTOR
    Tnode(){
      data = 0;
      left = right = NULL;
    }
    
    //PARAMETERISED CONSTRUTCOR
    Tnode( int d ){
      data = d;
      left = right = NULL;
    }
    
};

class BST{
  public :
    Tnode *root;
    //DEFAULT CONSTRICTOR TO INITIALIZE ROOT
    BST(){
      root = NULL;
    }
    
    void insert( Tnode* );
    void display( Tnode*, int );
    void search( int );
 
};


void BST :: insert( Tnode *new_node ){
 
  if( root == NULL ){
    root = new_node;
    cout<<"Value has been Inserted "<<endl; 
  }
  else{
       Tnode *temp;
       temp = root;
       
       while( temp!= NULL ){
         
         if( new_node->data == temp->data ){
           cout<<"Duplicates not allowed "<<endl;
           return;
         }
         
         else 
          if( (new_node->data < temp->data) && temp->left == NULL){
            temp->left = new_node;
            cout<<"Value inserted at left "<<endl;
            break;
       }
         else
          if( new_node->data < temp->data ){
          temp = temp->left;
       }
       
         else 
          if( (new_node->data > temp->data) && temp->right == NULL){
            temp->right = new_node;
            cout<<"Value inserted at left "<<endl;
            break;
            }
         else
          if( new_node->data > temp->data ){
          temp = temp->right;
        }
      }  
    }
  }
  

void BST :: display (Tnode *r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    display(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> data << "\n"; // 6
    display(r -> left, space); // Process left child  7
  }
 
void BST :: search( int x ){
  Tnode *temp = root;
  while( temp!= NULL ){
    if( x < temp->data ){
      temp = temp->left;
    }
    else if( x > temp->data ){
      temp = temp->right;
    }
    else if( x == temp->data ){
      cout<<"Value Has been found "<<endl;
      temp = NULL;
      return;
    }
  }
  
  cout<<"Value is not in the BST "<<endl;
}
  
int main(){
  BST obj;
  int val, n;
  cout<<"Enter the no. of nodes "<<endl;
  cin>>n;
  for( int i = 0; i < n; i++ ){
    cout<<i<<"th node "<<endl;
    Tnode *new_node = new Tnode();
    cin>>val;
    new_node->data = val;
    obj.insert( new_node );
  }
  
   obj.display( obj.root, 5 );
   
   cout<<"Enter the value to be searched"<<endl;
   int x;
   cin>>x;
   obj.search(x);
}

