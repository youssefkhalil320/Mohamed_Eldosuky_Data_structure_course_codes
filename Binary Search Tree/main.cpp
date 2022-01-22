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

    Node* Search(Node* r, int key)
    {
        if (r == NULL)
        {
            return NULL;
        }

        else if (r->data == key)
        {
            return r;
        }

        else if(r->data > key)
        {
            Search(r->left, key);
        }

        else 
        {
            Search(r->right, key);  
        }
    } 

    bool Search(int key)
    {
        Node* result = Search(root, key);
        if(result == NULL)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }

    Node* Findmin(Node* r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if(r-> left == NULL)
        {
            return r;
        }
        else
        {
            return Findmin(r->left);
        }
    }

    Node* Findmax(Node* r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if(r-> right == NULL)
        {
            return r;
        }
        else
        {
            return Findmin(r->right);
        }
    }

    Node* Delete(Node* r,int key)
    {
        if(r == NULL)
        {
            return NULL;
        }
        else if (key < r->data)
        {
            r->left = Delete(r->left, key);
        }
        else if (key > r->data)
        {
            r->right = Delete(r->right, key);
        }
        else
        {
            if (r->left == NULL && r->right == NULL) // leaf node
				r = NULL;
			else if (r->left != NULL && r->right == NULL) // one child on the left
			{
				r->data = r->left->data;
				delete r->left;
				r->left = NULL;
			}
			else if (r->left == NULL && r->right != NULL) // one child on the right
			{
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			else
			{
				Node* max = Findmax(r->left);
				r->data = max->data;
			   r->left=	Delete(r->left, max->data);
				
			}
        }
    return r;  
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
    int my_key;
    cout<<"Enter the key"<<endl;
    cin>>my_key;
    cout<<my_tree.Search(my_key);
}