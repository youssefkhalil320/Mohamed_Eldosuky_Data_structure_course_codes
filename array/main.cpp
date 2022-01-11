#include<iostream>
using namespace std;


class Array
{
private:
    int size;
    int length =0;
    int* items;

public:    
    Array(int arr_size)
    {
        size = arr_size;
        length =0;
        items = new int[arr_size];
    }
    void fill()
    {
        int num;
        cout<<"Please enter the number of items you want to enter"<<endl;
        cin>>num;
        if(num > size)
        {
            cout<<"Can not exceed the array size, Enter a valid number";
            return;
        }
        else
        {
            for(int i=0; i<num; i++)
            {
                cin>>items[i];
                length++;
            }
        }
    }

    void display()
    {
        cout<<"Display array items"<<endl;
        cout<<"[";
        for(int i=0; i<length; i++)
            {
                cout<<items[i]<<" ";
            }
        cout<<"]";  
    }

    int get_size()
    {
        return size;
    }

    int get_length()
    {
        return length;
    }

    int search(int number)
    {
        int index =-1; 
        for(int i=0; i<length; i++)
        {
            if(items[i] == number)
            {
                index =i;
                break;
            }
            return index;
        }

    }

    void insert(int new_item, int index)
    {
        if(index <= size && index >= 0 && length < size)
        {
            for(int i=length; i > index; i--)
            {
                items[i]= items[i-1];
            }
            items[index] = new_item;
            length++;
        }
        else
        {
            cout<<"index out of range or array is full"<<endl;
        }
    }

    void append_element(int added_item)
    {
        if(length < size)
        {
            items[length] = added_item;
            length++;
        }
        else
        {
            cout<<"The array is already full";
        }
    }

    void delete_element(int index)
    {
        if(index <= size && index >= 0)
        {
            for(int i=index; i < length-1; i++)
            {
                items[i]= items[i+1];
            }
            length--;
        }
        else
        {
            cout<<"index out of range or array is full"<<endl;
        }
    }

    void enlarge()
    {
        int new_size;
        cout<<"please Enter the size u want"<<endl;
        if(new_size <= size)
        {
            cout<<"Please enter a size nigger than the current size";
        }
        else
        {
            size = new_size;
            int* old = items;
            items = new int[new_size];
            for(int i=0; i<length; i++)
            {
                items[i]= old[i];
            }
            delete[]old;
        }
    }
};

int main()
{
cout<<"Demo array Activated";
int arr_size;
int wanna_find;
cin>>arr_size;
Array my_arr(arr_size);
my_arr.fill();
my_arr.display();
cout<<" "<<endl;
cout<<"Size ="<<my_arr.get_size()<<endl;
cout<<"length ="<<my_arr.get_length()<<endl;
cout<<"Enter the value of the item u wanna search about"<<endl;
cin>>wanna_find;
int res = my_arr.search(wanna_find);
if (res == -1)
{
    cout<<"Invalid Number"<<endl;
}
else
{
    cout<<"The item is @ position "<<res;
}

my_arr.append_element(6);
my_arr.delete_element(3);
my_arr.display();

}