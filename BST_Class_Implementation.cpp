#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left_child;
        Node* right_child;
        Node(int x){
            data = x;
            left_child = NULL;
            right_child = NULL;
        }
};

class BST{
    public:
    //Initially root is null
    Node* root = NULL;

    void insert(Node*& node, int data){
        if(node == NULL){
            node = new Node(data);
            return;
        }
        if(data < node->data){
            insert(node->left_child,data);
        }
        else if(data > node->data){
            insert(node->right_child,data);
        }

    }
    void just_insert(int data){
        insert(root,data);
    }
    void print(Node* node){
        if(node == NULL){
            return;
        }
        cout<<node->data<<" ";
        print(node->left_child);
        print(node->right_child);
    }
    void just_print(){
        print(root);
    }
};

int main() {
    //For fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n;
    BST bst = BST();
    for(int i=0; i<n; i++){
        cin>>x;
        bst.just_insert(x);
    }
    bst.just_print();
    return 0;
}
