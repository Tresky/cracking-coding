/*
 * File: ch2-2.cpp
 * Date: 08-05-15
 * 
 * Implement an algorithm to find the nth to last
 * element of a singly linked list.
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

// Discovers the size of the linked list and
// then finds the _n-th to last node.
int NthNode(NodePtr _head, int _n)
{
    int size = 0;

    // Compute the size of the list
    NodePtr node = _head;
    while (node->next != nullptr)
    {
        node = node->next;
        ++size;
    }

    if (_n > size)
        return -1;

    // Find desired element at position size - _n
    node = _head;
    for (int i = 0; i < size - _n; i++)
        node = node->next;

    return node->data;
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

    int n = 3;
    cout << "The " << n << "th to last element is: " << NthNode(head, n) << endl;

    return 0;
}