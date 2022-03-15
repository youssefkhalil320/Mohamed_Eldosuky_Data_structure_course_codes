#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node()
    {
        data = 0;
        next = NULL;
    }
};

class linkedList
{
public:
    int linked_list_length = 0;
    node* head;
    linkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insert_first(int new_item)
    {
        node* new_node = new node();
        new_node ->data = new_item;
        if(isEmpty() == true)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        linked_list_length++;
    }

    void append(int newvalue)
	{
		if (isEmpty())
			insert_first(newvalue);
		else
		{
            node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node* newnode = new node();
            newnode->data = newvalue;
            temp->next = newnode;
            newnode->next = NULL;
		}
        linked_list_length++;		
	}

    void insert_at(int value, int index)
    {
        if (index >= linked_list_length || index <0)
        {
            cout<<"Invalid index"<<endl;
        }
        else if(index == 0)
        {
            insert_first(value);
        }
        else if ( index == linked_list_length-1)
        {
            append(value);
        }
        else
        {
            node* temp = head;
            for(int i = 0; i < index-1; i++)
            {
                temp = temp->next;
            }
            node* next_node = temp->next;
            node* new_node= new node();
            new_node->data = value;
            new_node->next = NULL;
            temp->next = new_node;
            new_node->next = next_node;
        }
    }

    void insert_sorted(int value)
    {
        if(isEmpty() == true)
        {
            head->data = value;
        }
        else
        {
            if( value <= head->data)
            {
                insert_first(value);
            }
            else
            {
                node* temp = head;
                int counter=0;
                while(temp->next != NULL)
                {
                    if(temp->next->data >= value)
                    {
                        insert_at(value,counter);
                    }
                    else
                    {
                        temp = temp->next;
                        counter++;
                    }
                }
            }
        }
    }

    int get_node_front(int aim)
    {
        if(isEmpty())
        {
            cout<<"The list is Empty"<<endl;
            return -1;
        }
        else
        {
            node* temp = head;
            int index =0;
            while(temp->next != NULL)
            {
                if(temp->data == aim)
                {
                    cout<<"Found in the index "<<index<<endl;
                    delete temp;
                    return index;
                }
                else
                {
                    index++;
                    temp = temp->next;
                }
            }
            if(temp->data == aim)
            {
                cout<<"Found in the index "<<index<<endl;
                return index;
            }
            cout<<"Not Found";
            return -1;
            delete temp;
        }
    }

    int get_node_back(int aim)
    {
        int real_index = get_node_front(aim);
        if(real_index >=0)
        {
            cout<<"found at index "<<linked_list_length- real_index<<endl;
            return linked_list_length- real_index ;
        }
        else
        {
            cout<<"Not Found "<<endl;
            return -1;
        }
    }

    void delete_front()
    {
        node* temp = head;
        head = head->next;
        delete temp;
        linked_list_length--;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"The list is Empty"<<endl;
        }
        else
        {
            if(head->next == NULL)
            {
                node* temp = head;
                head = NULL;
                delete temp;
                linked_list_length--;
            }
            else
            {
                node* temp = head;
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                node* last_node = temp->next;
                temp->next = NULL;
                delete last_node;
                linked_list_length--;
            }
        }
    }

    void pop(int node_index)
    {
        if(node_index >= linked_list_length)
        {
            cout<<"Invalid Index"<<endl;
        }
        else if(node_index == linked_list_length-1 )
        {
            pop();
            linked_list_length--;
        }
        else if(node_index == 0)
        {
            if(head-> next == NULL)
            {
                head = NULL;
            }
            else
            {
                node* temp = head;
                head = head->next;
                delete temp;
            }
            linked_list_length--;
        }
        else
        {
            int counter=0;
            node* temp = head;
            while(counter < node_index-1)
            {
                temp = temp->next;
                counter++;
            }
            node* deleted_node = temp->next;
            temp->next = temp->next->next;
            delete deleted_node;
            linked_list_length--;
        }
    }

    void delete_data(int num)
    {
        node* temp = head;
        int counter = 0;
        while(temp->data != num)
        {
            counter++;
            temp = temp->next;
        }
        pop(counter);
        linked_list_length--;
        delete temp;
    }

    void swap_pairs()
    {
        node* temp = head;
        while(temp!= NULL && temp->next != NULL)
        {
            int temp_val = temp->data;
            temp->data = temp->next->data;
            temp->next->data = temp_val;
            temp = temp->next->next;
        }
    }

    void left_rotate()
    {
        node* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node* tail = temp->next;
        tail->next = head;
        temp->next = NULL;
        head = tail;
    }

    void swap_head_tail()
    {
        node* temp = head;
        node* after_next = head->next;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node* tail = temp->next;
        temp->next = head;
        tail->next = after_next;
        head-> next = NULL;
        head = tail;
    }

    void removeDuplicates()
    {
        node *ptr1, *ptr2, *dup;
        ptr1 = head;
    
        /* Pick elements one by one */
        while (ptr1 != NULL && ptr1->next != NULL) {
            ptr2 = ptr1;
    
            /* Compare the picked element with rest
            of the elements */
            while (ptr2->next != NULL) {
                /* If duplicate then delete it */
                if (ptr1->data == ptr2->next->data) {
                    /* sequence of steps is important here */
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete (dup);
                }
                else /* This is tricky */
                    ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }

    void reverse()
    {
        node* curr = head;
        node* prev = NULL;
        node* next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display()
    {
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<"******************"<<endl;
        delete temp;
    }

    ~linkedList()
    {
        node* temp = head;
        while(temp != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        cout<<"******************"<<endl;
        delete temp;
    }

};

int main()
{
    linkedList my_list;
    my_list.insert_first(1);
    my_list.insert_first(2);
    my_list.insert_first(3);
    my_list.insert_first(4);
    
    /*
    my_list.append(5);
    my_list.display();
    my_list.delete_front();
    my_list.display();
    my_list.get_node_front(5);
    my_list.get_node_back(3);
    */
    linkedList new_list;
    new_list.insert_first(1);
    new_list.insert_first(2);
    new_list.insert_first(1);
    new_list.insert_first(3);
    new_list.insert_first(6);
    new_list.insert_first(4);
    new_list.insert_first(6);
    new_list.insert_first(4);
    //new_list.delete_data(3);
    //new_list.swap_pairs();
    //new_list.display();
    //new_list.reverse();
    //new_list.insert_at(6,2);
    //new_list.display();
    //new_list.left_rotate();
    //new_list.display();
    //new_list.swap_head_tail();
    new_list.display();
    new_list.removeDuplicates();
    new_list.display();
    
}