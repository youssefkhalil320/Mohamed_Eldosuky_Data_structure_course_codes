#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;  
    Node(int my_item)
    {
        data=my_item;
        left = right= NULL;
    }
};

class BST
{
public:
    Node* root;
    BST()
    {
        root = NULL;
    }
    Node* insert(Node* r , int item)
    {
        if(r== NULL)
        {
            Node* New_node = new Node(item);
            r = New_node;
        }
        else if(item < r->data)
        {
            r->left = insert(r->left, item);
        }
        else
        {
            r->right = insert(r->right, item);
        }
        return r;
    }

    void insert(int item)
    {
        root = insert(root, item);
    }

    void preorder(Node* r) //root -> left-> right
    {
        if(r == NULL)
        {
            return;
        }
        else
        {
            cout<<r->data<<"\t";
            preorder(r->left);
            preorder(r->right);           
        }
    }

    void inorder(Node* r) // left-> root ->right
    {
        if(r == NULL)
        {
            return;
        }
        else
        {
            
            inorder(r->left);
            cout<<r->data<<"\t";
            inorder(r->right);           
        }
    }

    void postorder(Node* r) // left-> right -> root
    {
        if(r == NULL)
        {
            return;
        }
        else
        {          
            postorder(r->left);
            postorder(r->right);   
            cout<<r->data<<"\t";        
        }
    }
};

int main()
{
    BST my_tree;
    my_tree.insert(10);
    my_tree.insert(111);
    my_tree.insert(12);
    my_tree.insert(13);
    my_tree.insert(5);
    my_tree.preorder(my_tree.root);
    cout<<"..................................."<<endl;
    my_tree.inorder(my_tree.root);
    cout<<"..................................."<<endl;
    my_tree.postorder(my_tree.root);
}