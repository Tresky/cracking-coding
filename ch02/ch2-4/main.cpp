/*
 * File: ch2-2.cpp
 * Date: 08-05-15
 * 
 *  
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

void DisplayList(NodePtr _head);

// Helper function to search for element in vector.
bool SearchVector(vector<int> _vec, int _query)
{
    for (int i = 0; i < _vec.size(); ++i)
        if (_vec[i] == _query)
            return true;
    return false;
}

// 
NodePtr PseudoSortList(NodePtr _head, int _axis)
{
    NodePtr head_one = nullptr, previous_one = nullptr;
    NodePtr head_two = nullptr, previous_two = nullptr;

    NodePtr node = _head;
    while (node->next != nullptr)
    {
        cout << "Data 1: " << node->data << endl;
        if (node->data < _axis)
        {
            if (head_one == nullptr)
            {
                head_one = new Node;
                head_one->data = node->data;
                head_one->next = nullptr;
                previous_one = head_one;
            }
            else
            {
                previous_one->next = new Node;
                previous_one->next->data = node->data;
                previous_one->next->next = nullptr;

                previous_one = previous_one->next;
            }
        }
        else
        {
            if (head_two == nullptr)
            {
                head_two = new Node;
                head_two->data = node->data;
                head_two->next = nullptr;
                previous_two = head_two;
            }
            else
            {
                previous_two->next = new Node;
                previous_two->next->data = node->data;
                previous_two->next->next = nullptr;

                previous_two = previous_two->next;
            }
        }
        cout << "Data 2: " << node->data << endl;
        node = node->next;
    }

    DisplayList(head_one);
    DisplayList(head_two);

    node = head_one;
    while (node->next != nullptr)
        node = node->next;
    node->next = head_two;

    return head_one;
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

    DisplayList(PseudoSortList(head, 5));

    return 0;
}