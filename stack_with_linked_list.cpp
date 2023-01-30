#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* nxt;
};

class singlyLinkedList
{
public:
    int sz;
    node* head;
    singlyLinkedList()
    {
        sz=0;
        head=NULL;
    }
    // creating newNode function
    node* CreateNewNode(int value)
    {
        // allocate memory for the new node;
        node* newNode = new node();
        newNode->data=value;
        newNode->nxt=NULL;
        return newNode;
    }
    // Insert at head;
    void InsertAtHead(int value)
    {
        node* newNode = CreateNewNode(value);
        // increase the size
        sz++;
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        newNode->nxt=head;
        head=newNode;
    }
    void DeleteAtHead()
    {
        if(sz==0)
        {
            cout << "The Linked list is empty!" << "\n";
            return;
        }
        node* temp = head;
        head=temp->nxt;
        delete temp;
        sz--;
    };
    void Traverse()
    {
        node* a = head;
        while(a!=NULL)
        {
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }
    int GetSize()
    {
        return sz;
    }
};

// implement the stack with linked list
class Stack
{
public:
    singlyLinkedList sl;
    Stack()
    {

    }
    int Top()
    {
        if(sl.GetSize() == 0)
        {
            cout << "THE STACK IS EMPTY!" << "\n";
            return -1;
        }
        return sl.head->data;
    }
    void Push(int val)
    {
        sl.InsertAtHead(val);
    }
    void Pop()
    {
        sl.DeleteAtHead();
    }
};

int main()
{
    Stack sl;
    sl.Push(3);
    cout << sl.Top() << "\n";
    sl.Push(2);
    cout << sl.Top() << "\n";
    sl.Push(1);
    cout << sl.Top() << "\n";
    sl.Pop();
    cout << sl.Top() << "\n";
    return 0;
}
