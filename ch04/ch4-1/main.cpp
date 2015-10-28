#include <iostream>

using namespace std;

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

class BinaryTree
{
public:
    BinaryTree()
        : head(nullptr)
    {}

    ~BinaryTree()
    {

    }

    void Insert(int _data)
    {
        if (head != nullptr)
            Insert(head, _data);
        else
        {
            head = new TreeNode;
            head->data = _data;
            head->left = nullptr;
            head->right = nullptr;
        }
    }

    int GetDepth()
    {
        return GetDepth(head);
    }

    bool IsBalanced()
    {
        int left_height = GetDepth(head->left);
        int right_height = GetDepth(head->right);
        if (abs(left_height - right_height) > 1)
            return false;
        return true;
    }

    void Display()
    {
        Display(head, 1);
    }

private:
    TreeNode* head;

    TreeNode* NewNode(int _data)
    {
        TreeNode* node = new TreeNode;
        node->data = _data;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    TreeNode* Insert(TreeNode* _node, int _data)
    {
        if (_node == nullptr)
            return NewNode(_data);

        int r = rand() % 2;
        if (_data <= _node->data)
            _node->left = Insert(_node->left, _data);
        else
            _node->right = Insert(_node->right, _data);

        return _node;
    }

    int GetDepth(TreeNode* _node)
    {
        if (_node == nullptr)
            return -1;

        int left_depth = GetDepth(_node->left);
        int right_depth = GetDepth(_node->right);
        return max(left_depth, right_depth) + 1;
    }

    void Display(TreeNode* _node, int _layer)
    {
        if (_node == nullptr ) {
            // for (int i = 0; i < _layer; i++)
            //     cout << "\t";
        }
        else
        {
            Display(_node->right, _layer + 1);
            for (int i = 0; i < _layer; i++)
                cout << "\t";
            cout << _node->data << endl;
            Display(_node->left, _layer + 1);
        }
    }
};

int main()
{
    srand(time(NULL));
    BinaryTree tree;

    for (int i = 0; i < 9; i++)
        tree.Insert(rand() % 10);

    cout << "Depth of Tree: " << tree.GetDepth() << endl;
    if (tree.IsBalanced())
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is not Balanced" << endl;

    tree.Display();
    return 0;
}