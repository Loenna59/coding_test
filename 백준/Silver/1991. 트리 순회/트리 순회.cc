#include <iostream>
#include <string>
#include <queue>

struct node
{
    char alphabet;
    node* first;
    node* second;

    static node* create(const char& alphabet)
    {
        return new node { alphabet, nullptr, nullptr };
    }
};

struct tree
{
    node* root;

    // 트리 생성
    static tree create(const char& alphabet)
    {
        tree t;
        t.root = node::create(alphabet);

        return t;
    }

    // 노드 찾기
    static node* find(node* root, const char& alphabet)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->alphabet == alphabet)
        {
            return root;
        }

        node* first = find(root->first, alphabet);

        if (first != nullptr)
        {
            return first;
        }

        return find(root->second, alphabet);
    }

    // 하위 노드 추가
    void add_node(const char& parent, const char& alphabet, bool left)
    {
        node* parent_node = find(root, parent);

        if (!parent_node)
        {
            return;
        }

        // 하위노드로 추가할 수 없음
        if (parent_node->first && parent_node->second)
        {
            return;
        }

        if (left && !parent_node->first)
        {
            parent_node->first = node::create(alphabet);
        }

        if (!left && !parent_node->second)
        {
            parent_node->second = node::create(alphabet);
        }
    }

    // 전위 순회 (preorder traversal)
    static void pre_order(node* start)
    {
        if (start == nullptr)
        {
            return;
        }

        std::cout << start->alphabet;
        pre_order(start->first);
        pre_order(start->second);
    }

    // 중위 순회 (in-order traversal)
    static void in_order(node* start)
    {
        if (start == nullptr)
        {
            return;
        }

        in_order(start->first);
        std::cout << start->alphabet;
        in_order(start->second);
    }

    // 후위 순회 (post-order traversal)
    static void post_order(node* start)
    {
        if (start == nullptr)
        {
            return;
        }

        post_order(start->first);
        post_order(start->second);
        std::cout << start->alphabet;
    }
};


int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    tree t = tree::create('A');

    for (int i = 0; i < n; i++)
    {
        char parent;
        char left;
        char right;

        std::cin >> parent >> left >> right;

        if (left != '.')
        {
            t.add_node(parent, left, true);
        }

        if (right != '.')
        {
            t.add_node(parent, right, false);
        }
    }

    tree::pre_order(t.root);
    std::cout << "\n";
    tree::in_order(t.root);
    std::cout << "\n";
    tree::post_order(t.root);
    
    return 0;
}