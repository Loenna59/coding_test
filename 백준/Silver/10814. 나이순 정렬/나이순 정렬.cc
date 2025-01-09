#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct node
{
    int index;
    int age;
    std::string str;

    node* left;
    node* right;

    static node* create(int index, int age, const std::string& str)
    {
        return new node
        {
            index,
            age,
            str,
            nullptr,
            nullptr
        };
    }
};

struct bst
{
    node* root = nullptr;

public:
    void insert(int index, const std::string& str)
    {
        std::stringstream ss(str);
        std::string age_str;
        ss >> age_str;

        if (!root)
        {
            root = node::create(index, std::stoi(age_str), str);
            return;
        }

        insert_impl(root, index, std::stoi(age_str), str);
    }

    void print()
    {
        print_impl(root);
    }

private:
    void insert_impl(node* current, int index, int age, const std::string& str)
    {
        if (age < current->age)
        {
            if (current->left)
            {
                insert_impl(current->left, index, age, str);
            }
            else
            {
                current->left = node::create(index, age, str);
            }

        }
        else if (age > current->age)
        {
            if (current->right)
            {
                insert_impl(current->right, index, age, str);
            }
            else
            {
                current->right = node::create(index, age, str);
            }
        }
        else
        {
            if (index < current->index)
            {
                if (current->left)
                {
                    insert_impl(current->left, index, age, str);
                }
                else
                {
                    current->left = node::create(index, age, str);
                }
            }
            else
            {
                if (current->right)
                {
                    insert_impl(current->right, index, age, str);
                }
                else
                {
                    current->right = node::create(index, age, str);
                }
            }
        }
    }

    void print_impl(node* start)
    {
        if (!start)
        {
            return;
        }

        print_impl(start->left);
        std::cout << start->str << "\n";
        print_impl(start->right);
    }
};

int main()
{
    int N;
    std::cin >> N;
    std::cin.ignore();

    bst tree;

    for (int i = 0; i < N; i++)
    {
        std::string input;
        getline(std::cin, input);
        tree.insert(i, input);
    }

    tree.print();
}