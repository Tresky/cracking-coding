/*
 * ch3-2
 * 
 *
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * The best way to keep track of the minimum value
 * within the stack is to have each node store the minimum
 * value of the sub-stack below itself.
 *
 * This allows the problem to take care of itself as items
 * are popped and pushed.
 *
 * All you need to do is, set the min value of the pushed node
 * according to the current top node. Whenever an element is 
 * popped, the new top node will contain the new minimum.
 */
struct node
{
    int data;
    int min;
    struct node* next;
};

typedef struct node Node;
typedef struct node* NodePtr;

// Push a new element into the stack.
// Be sure to check and set the min value in the
// element accordingly in relation to the current
// top element.
NodePtr Push(NodePtr _top, int _data)
{
    cout << " - Adding Element: " << _data << endl;
    NodePtr node = new Node;
    node->data = _data;
    node->next = _top;
    if (_top)
        node->min = (_top->min < _data) ? _top->min: _data;
    else
        node->min = _data;

    return node;
}

int Pop(NodePtr _top)
{
    cout << " - Popping Element: " << _top->data << endl;

    int temp = _top->data;
    NodePtr old_next = _top->next;
    _top->data = _top->next->next->data;
    _top->next = _top->next->next;

    delete old_next;

    return temp;
}

int GetMin(NodePtr _top)
{
    cout << "\t - Current Min: " << _top->min << endl;
    return _top->min;
}

int main()
{
    NodePtr head = Push(nullptr, 8);
    GetMin(head);

    head = Push(head, 4);
    GetMin(head);

    head = Push(head, 3);
    GetMin(head);

    head = Push(head, 10);
    GetMin(head);

    head = Push(head, 15);
    GetMin(head);

    head = Push(head, 6);
    GetMin(head);
    return 0;
}