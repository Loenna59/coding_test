#include <iostream>

struct node
{
    int data;
    node* left;
    node* right;

    static node* create(int value)
    {
        return new node { value, nullptr, nullptr };
    }
};

struct bst
{
    node* root = nullptr;

public:
    // insert
    void insert(int value)
    {
        if (!root)
        {
            root = node::create(value);
            return;
        }

        insert_impl(root, value);
    }

    void post_order()
    {
        post_order_impl(root);
    }

private:
    void insert_impl(node* current, int value)
    {
        if (value < current->data)
        {
            if (!current->left)
            {
                current->left = node::create(value);
            }
            else
            {
                insert_impl(current->left, value);
            }
        }
        else
        {
            if (!current->right)
            {
                current->right = node::create(value);
            }
            else
            {
                insert_impl(current->right, value);
            }
        }
    }

    void post_order_impl(node* start)
    {
        if (!start) return;

        post_order_impl(start->left);
        post_order_impl(start->right);
        std::cout << start->data << "\n";
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    bst tree;
    int x;

    while (std::cin >> x)
    {
        tree.insert(x);
    }

    tree.post_order();


    return 0;
}