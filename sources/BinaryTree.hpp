#pragma once

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        struct Node
        {
            T value;
            Node *right, *left;
            Node(const T &val) : value(val) {}
        };
        Node root;

    public:
        BinaryTree() {}
        ~BinaryTree() {}
        BinaryTree &add_root(const T &val) {}
        BinaryTree &add_left(const T &val, const T &child) {}
        BinaryTree &add_right(const T &val, const T &child) {}
        class preorder_iterator {
            private:
                Node* current_node;
            private:
                preorder_iterator(Node* ptr = nullptr):current_node(ptr){}
                T& operator*() const{}
                T* operator->()const{}
                  


        };
    
    };
}