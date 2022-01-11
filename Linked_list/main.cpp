#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class linkedList
{
public:
    Node* head;
    linkedList()
    {
        head =NULL;
    }

    bool is_empty()
    {
        return (head == NULL);
    }

   void insert_new(int value)
{
    Node* new_node;
    new_node = new Node;
    new_node->data = value; 

    if(head == NULL)
    {
        head = new_node;
        new_node-> next = NULL;   
    }
    else
    {
        Node* last = head;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }
}

     int counter()
    {
        int counter = 0;
        Node* temp = head;
        while(temp != NULL)
        {
            counter++;
            temp = temp-> next;
        }
        return counter;
    }

    bool is_found(int key)
    {
        Node* temp = head;
        bool flag = false;
        while(temp != NULL)
        {
           if(temp-> data == key )
           {
               flag = true;
           }
           temp = temp ->next; 
        }
        return flag;
    }

     void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp-> next;
        }

    }  
};

int main()
{
    linkedList my_list;
    int new_element;
    if(my_list.is_empty())
    {
        cout<<"The list is empty\n";
    }
    else
    {
        cout<<my_list.counter()<<endl;
    }
    cout<<"Please Enter a number to insert in the list"<<endl;
    cin>>new_element;
    my_list.insert_new(new_element);
    my_list.display();
    
}                                                                                                                               