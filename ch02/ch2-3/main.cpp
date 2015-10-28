/*
 * File: ch2-1.cpp
 * Date: 08-05-15
 * 
 * Write code to remove duplicates from
 * an unsorted linked list.
 */

#include <iostream>
#include <vector>

using namespace std;

// Declare node structure
struct node {
    int data;
    struct node* next;
};

typedef struct node Node;
typedef struct node* NodePtr;

// Helper function to search for element in vector.
bool SearchVector(vector<int> _vec, int _query)
{
    for (int i = 0; i < _vec.size(); ++i)
        if (_vec[i] == _query)
            return true;
    return false;
}

// Delete the given node by transerring the next's data
// into the node and deleting the next node.
void DeleteItem(NodePtr _node)
{
    cout << "Deleting Value: " << _node->data << endl;

    NodePtr temp = _node->next;
    _node->data = _node->next->data;
    _node->next = _node->next->next;
    delete temp;
}

// Creates a list recursively with a specified size.
NodePtr CreateList(int _size)
{
    if (_size < 1)
        return nullptr;

    NodePtr node = new Node;
    node->data = rand() % 10;
    node->next = CreateList(_size - 1);
    return node;
}

// Displays the linked list.
void DisplayList(NodePtr _head)
{
    cout << "Displaying List:\n\t";
    NodePtr node = _head;
    while (node->next != nullptr)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    srand(time(NULL));

    NodePtr head = CreateList(10);

    DisplayList(head);

    DeleteItem(head->next->next->next);

    DisplayList(head);

    return 0;
}