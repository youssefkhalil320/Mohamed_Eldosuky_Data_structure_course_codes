#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node()
    {
    data = 0;
    next = NULL;
    }    
};

class Queue 
{
public:    
    Node* front;
    Node* rear;
    Queue()
    {
        front = rear = NULL;
    }

    bool is_empty()
    {
        if(front == NULL)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void enqueue(int x)
    {
        Node* new_node = new Node();
        new_node -> data = x;
        if(is_empty())
        {
            front = rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
         
    }

    void display()
    {
        if(is_empty())
        {
            cout<<"The Queue is Empty"<<endl;
        }
        else
        {
            Node* temp = front;
            while (temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;                                                  
            }
            cout<<endl;
        }
    }

    void Dequeue()
    {
        if(is_empty())
        {
            cout<<"The Queue is empty";
        }
        else if( rear->next == front)
        {
            delete front;
            front = rear = NULL;
        }
        else 
        {
            Node* delptr = front;
            front = front->next;
            delete delptr;
        }
        
    }

    int counter()
    {
        int counter =0;
        Node* temp = front;
        while(temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    int is_found(int item)
    {
        bool found = false;
        Node* temp = front;
        while(temp != NULL)
        {
           if(temp->data == item)
           {
               found = true;
           }
           temp = temp->next;
        }
        return found;
    }

    int get_front()
    {
        return front->data;
    }

    int clear()
    {
        while(!is_empty())
        {
          Dequeue();  
        }
    }
};

int main()
{
    Queue my_queue;
    for(int i =0; i <5; i++)
    {
        int item;
        cout<<"Please Enter a new Number"<<endl;
        cin>>item;
        my_queue.enqueue(item);
    }
    my_queue.display(); 
    /*
    my_queue.display();  
    my_queue.Dequeue(); 
    my_queue.display();  
    */
   cout<<"Clear all items"<<endl;
   my_queue.clear();
   my_queue.display();  
}