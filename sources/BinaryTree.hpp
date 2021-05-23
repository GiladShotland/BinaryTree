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
            Node *right, *left , *father;
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
                preorder_iterator& operator++() {} //prefox
                preorder_iterator operator++(int){} //postfix
                bool operator==(const preorder_iterator& it) const{}
                bool operator!=(const preorder_iterator& it) const{}
        };
        class inorder_iterator {
            private:
                Node* current_node;
            private:
                inorder_iterator(Node* ptr = nullptr):current_node(ptr){}
                T& operator*() const{}
                inorder_iterator& operator++() {} //prefox
                inorder_iterator operator++(int){} //postfix
                bool operator==(const inorder_iterator& it) const{}
                bool operator!=(const inorder_iterator& it) const{}
        };
        class postorder_iterator {
            private:
                Node* current_node;
            private:
                postorder_iterator(Node* ptr = nullptr):current_node(ptr){}
                T& operator*() const{}
                postorder_iterator& operator++() {} //prefox
                postorder_iterator operator++(int){} //postfix
                bool operator==(const postorder_iterator& it) const{}
                bool operator!=(const postorder_iterator& it) const{}
        };
    
    };
}