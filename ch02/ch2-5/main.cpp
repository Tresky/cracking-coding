#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef node Node;
typedef node* NodePtr;

void AddNode(NodePtr _head, int data);

NodePtr AddLists(NodePtr _head_one, NodePtr _head_two)
{
    NodePtr new_list = nullptr;

    int data_one = 0, data_two = 0, carry = 0;

    NodePtr run_one = _head_one, run_two = _head_two;
    while (run_one || run_two)
    {
        if (!run_one)
            data_one = 0;
        else
            data_one = run_one->data;
        if (!run_two)
            data_two = 0;
        else
            data_two = run_two->data;

        int sum = data_one + data_two + carry;
        if (sum > 9)
        {
            int temp = sum;
            sum = sum % 10;
            carry = 1;
        }
        else
            carry = 0;

        if (!new_list)
        {
            new_list = new Node;
            new_list->data = sum;
            new_list->next = nullptr;
        }
        else
            AddNode(new_list, sum);

        if (run_one)
            run_one = run_one->next;
        if (run_two)
            run_two = run_two->next;
    }
    return new_list;
}

// Adds a node to the specified linked list's head
void AddNode(NodePtr _head, int _data)
{
    NodePtr node = _head;
    while (node->next != nullptr)
        node = node->next;

    node->next = new Node;
    node->next->data = _data;
    node->next->next = nullptr;
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
    NodePtr head_one = new Node;
    head_one->data = 2;
    head_one->next = nullptr;
    AddNode(head_one, 1);
    AddNode(head_one, 2);
    AddNode(head_one, 6);
    DisplayList(head_one);

    NodePtr head_two = new Node;
    head_two->data = 8;
    head_two->next = nullptr;
    AddNode(head_two, 9);
    DisplayList(head_two);

    NodePtr new_list = AddLists(head_one, head_two);

    DisplayList(new_list);

    DeleteList(head_one);
    DeleteList(head_two);
    DeleteList(new_list);

    return 0;
}