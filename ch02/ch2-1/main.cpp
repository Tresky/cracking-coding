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

// Finds and deletes the duplicated values within
// the linked list by using a temporary buffer to store
// values that have been found.
void DeleteDuplicates(NodePtr _head)
{
    cout << "Deleting Duplicate Values" << endl;
    vector<int> nodes;

    NodePtr node = _head, previous = nullptr;
    while (node->next != nullptr)
    {
        if (SearchVector(nodes, node->data))
        {
            previous->next = node->next;
            delete node;
            node = previous->next;
        }
        else
        {
            nodes.push_back(node->data);
            previous = node;
            node = node->next;
        }
    }
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

    DeleteDuplicates(head);

    DisplayList(head);

    return 0;
}