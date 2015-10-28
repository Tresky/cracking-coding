#include <iostream>
#include <climits>

using namespace std;

class Stack
{
public:
    Stack()
        : elements(new int[10])
        , top(0)
    {}

    ~Stack()
    {
        delete[] elements;
    }

    void Push(int _data)
    {
        if (top < 10)
        {
            elements[top] = _data;
            top++;
        }
        else
            cout << "Stack is full" << endl;
    }

    int Pop()
    {
        if (!IsEmpty())
        {
            int temp = elements[top - 1];
            top--;
            return temp;
        }
        else
        {
            cout << "No elements to pop" << endl;
            exit(-1);
        }
    }

    int Peek()
    {
        if (!IsEmpty())
            return elements[top - 1];
        else
            return INT_MIN;
    }

    bool IsEmpty()
    {
        if (top <= 0)
            return true;
        return false;
    }

    void PrintStack()
    {
        cout << "--------" << endl;
        for (int i = top - 1; i >= 0; i--)
            cout << "|  " << elements[i] << "  |" << endl;
        cout << "--------" << endl;
    }

private:
    // Array holding the elements
    int* elements;

    int top;
};

void SortStack(Stack *_stack)
{
    Stack temp_stack;

    temp_stack.Push(_stack->Pop());
    while (!_stack->IsEmpty())
    {
        while (!_stack->IsEmpty() && _stack->Peek() > temp_stack.Peek())
        {
            cout << "#1 -> " << _stack->Peek() << " transferred to #2 -> " << temp_stack.Peek() << endl;
            temp_stack.Push(_stack->Pop());
        }

        if (_stack->Peek() == INT_MIN)
            break;

        _stack->PrintStack();
        temp_stack.PrintStack();

        int temp = _stack->Pop();
        cout << " - Temp Saved: " << temp << endl;
        while (!temp_stack.IsEmpty() && temp_stack.Peek() > temp)
        {
            cout << "#2 -> " << temp_stack.Peek() << " transferred to #1 -> " <<
                _stack->Peek() << endl;

            _stack->Push(temp_stack.Pop());
        }
        if (!_stack->IsEmpty())
            temp_stack.Push(temp);
    }

    while (!temp_stack.IsEmpty())
        _stack->Push(temp_stack.Pop());
}

int main()
{
    Stack *stack = new Stack;
    stack->Push(10);
    stack->Push(15);
    stack->Push(74);
    stack->Push(23);
    stack->Push(12);

    stack->PrintStack();

    SortStack(stack);

    stack->PrintStack();
    return 0;
}