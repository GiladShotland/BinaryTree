#pragma once
#include <iostream>

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    protected:
        struct Node
        {
            T value;
            Node *right, *left, *father;
            Node(const T &val) : value(val) {}
        };
        Node *root; //member of the tree

    public:
        BinaryTree(){
            this->root = nullptr;
        }
        ~BinaryTree() {}
        friend std::ostream &operator<<(std::ostream &stream, const BinaryTree<T> &tree){return stream;}
        BinaryTree &add_root(const T &val) {return *this;}
        BinaryTree &add_left(const T &val, const T &child) {return *this;}
        BinaryTree &add_right(const T &val, const T &child) {return *this;};
        T *operator->()const{T value;
        return value;}
        
        class preorder_iterator
        {
        private:
            Node *current_node;
            

        public:
            preorder_iterator(Node *ptr = nullptr) : current_node(ptr) {}
            T &operator*() const {return current_node->value;}
            preorder_iterator &operator++() {return *this;}  //prefox
            preorder_iterator operator++(int) {return *this;} //postfix
            bool operator==(const preorder_iterator &it) const {return false;}
            bool operator!=(const preorder_iterator &it) const {return false;}
            preorder_iterator &operator=(const preorder_iterator &iterator){return iterator;}
            T *operator->()const{T ans;
            return ans;}
            int size(){return 0;}
        };
        class inorder_iterator
        {
        private:
            Node *current_node;
           

        public:
            inorder_iterator(Node *ptr = nullptr) : current_node(ptr) {}
            T &operator*() const {return current_node->value;}
            inorder_iterator &operator++(){return *this;}   //prefox
            inorder_iterator operator++(int) {return *this;} //postfix
            bool operator==(const inorder_iterator &it) const {return false;}
            bool operator!=(const inorder_iterator &it) const {return false;}
            inorder_iterator &operator=(const inorder_iterator &iterator){return iterator;}
            T *operator->()const{T ans; return ans;}
            int size(){return 0;}
            
        };
        class postorder_iterator
        {
        private:
            Node *current_node;
            

        public:
            postorder_iterator(Node *ptr = nullptr) : current_node(ptr) {}
            T &operator*() const {return current_node->value;}
            postorder_iterator &operator++() {return *this;}  //prefox
            postorder_iterator operator++(int){return *this;}  //postfix
            bool operator==(const postorder_iterator &it) const{return false;}
            bool operator!=(const postorder_iterator &it) const {return false;}
            postorder_iterator &operator=(const postorder_iterator &iterator){return iterator;} 
            T *operator->()const {
            return nullptr;
            }
            int size(){return 0;}
        };
        inorder_iterator begin(){return inorder_iterator();} 
        inorder_iterator end() {return inorder_iterator();}
        inorder_iterator begin_inorder() {return inorder_iterator();} 
        inorder_iterator end_inorder() {return inorder_iterator();} 
        preorder_iterator begin_preorder() {return preorder_iterator();}
        preorder_iterator end_preorder() {return preorder_iterator();}
        postorder_iterator begin_postorder() {return postorder_iterator();}
        postorder_iterator end_postorder() {return postorder_iterator();}
    };
}