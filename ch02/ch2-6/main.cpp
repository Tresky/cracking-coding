#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node Node;
typedef struct node* NodePtr;

NodePtr CreateList(int _size)
{
    if (_size < 1)
        return nullptr;

    NodePtr node = new Node;
    node->data = rand() % 10;
    node->next = CreateList(_size - 1);

    return node;
}

NodePtr FindCircular(NodePtr _head)
{
    if (!_head->next && !_head->next->next)
    {
        cout << "Not enough elements" << endl;
        return nullptr;
    }

    NodePtr node = _head, runner = _head->next;
    while (node)
    {
        if (node == runner)
            return runner;

        node = node->next;
        runner = runner->next->next;
    }
    return nullptr;
}

// Displays the linked list.
void DisplayList(NodePtr _head)
{
    cout << "Displaying List:\n\t";
    NodePtr node = _head;
    while (node != nullptr)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

// Deletes a linked list to free memory.
void DeleteList(NodePtr _head)
{
    while (_head != nullptr)
    {
        NodePtr temp = _head->next;
        delete _head;
        _head = temp;
    }
}

int main()
{
    NodePtr head = CreateList(10);
    cout << "List Created" << endl;

    DisplayList(head);

    // This makes it circular... I hate myself...
    head->next->next->next->next->next = head;
    cout << "Circle Made at: " << head->next->next->next->next << " -> " << head->next->next->next->next->data << endl;

    NodePtr overlap = FindCircular(head);
    if (overlap)
        cout << "Overlap is at: " << overlap << " -> " << overlap->data << endl;
    else
        cout << "No loops found in the linked list." << endl;

    //DeleteList(head);

    return 0;
}