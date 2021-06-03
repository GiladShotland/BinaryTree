#pragma once
#include <stack>
#include <queue>
#include <iostream>
namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        struct Node
        {
            T value;
            Node *left;
            Node *right;
            Node *parent;
            Node() = default;
            Node(T val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
            bool operator==(const Node &other)
            {
                return this->value = other->value && this->right == other->right && this->left == other->left && this->father == other->father;
            }
            bool operator!=(const Node &other)
            {
                return this->value != other->value || this->right != other->right || this->left != other->left || this->parent != other->parent;
            }
        };
        Node *root;

    public:
        BinaryTree() : root(nullptr) {}
        friend std::ostream &operator<<(std::ostream &stream, const BinaryTree<T> &tree) { return stream; }
        class InorderIterator
        {
        private:
            std::stack<Node *> stk;

        protected:
            Node *current;

        /*Ideas to iterators algorithms - TechDose channel at YouTube
        */
        public:
            InorderIterator() : current(nullptr) {}
            InorderIterator(Node *root) : current(root)
            {
                while (current)
                {
                    stk.push(current);
                    current = current->left;
                }
                if (!stk.empty())
                    current = stk.top(); 
                else
                {
                    current = nullptr;
                }
            }

            T *operator->() const
            {
                return &(current->value);
            }
            T &operator*() const
            {
                return current->value;
            }
            InorderIterator &operator++()
            {
                if (stk.empty())
                {
                    this->current = nullptr;
                    return *this;
                }
                Node *traverse = stk.top();
                stk.pop();
                if (traverse->right)
                {
                    stk.push(traverse->right);
                    traverse = traverse->right->left;
                    while (traverse)
                    {
                        stk.push(traverse);
                        traverse = traverse->left;
                    }
                }
                this->current = stk.empty() ? nullptr : stk.top();
                return *this;
            }
            InorderIterator operator++(int)
            {
                InorderIterator now = *this;
                ++*this;
                return now;
            }
            bool operator==(const InorderIterator &other) const
            {
                return current == other.current;
            }
            bool operator!=(const InorderIterator &other) const
            {
                return current != other.current;
            }
            Node *get_current(){
                return current;
            }
        };
        InorderIterator begin_inorder()
        {
            return InorderIterator(root);
        }
        InorderIterator end_inorder()
        {
            return InorderIterator();
        }
        class PostorderIterator
        {
        private:
            std::stack<Node *> first_stk, second_stk;

       
            

        public:
            Node *current;
            PostorderIterator() : current(nullptr) {}
            PostorderIterator(Node *root)
            {
                if (root)
                {
                    first_stk.push(root);
                    Node *temp = root;
                    while (!first_stk.empty())
                    {
                        temp = first_stk.top();
                        first_stk.pop();
                        second_stk.push(temp);
                        if (temp->left)
                        {
                            first_stk.push(temp->left);
                        }
                        if (temp->right)
                        {
                            first_stk.push(temp->right);
                        }
                    }
                    
                    this->current = second_stk.top();
                }
            }
            T &operator*() const
            {
                return this->current->value;
            }
            T *operator->() const
            {
                return &(this->current->value);
            }
            //prefix
            PostorderIterator &operator++()
            {
                second_stk.pop();
                if (second_stk.empty())
                {
                    this->current = nullptr;
                    return *this;
                }
                this->current = second_stk.top();
                return *this;
            }
            PostorderIterator operator++(int)
            {
                PostorderIterator now = *this;
                ++*this;
                return now;
            }
            bool operator==(const PostorderIterator &other) const
            {
                return this->current == other->current;
            }
            bool operator!=(const PostorderIterator &other) const
            {
                return current != other.current;
            }
            
            Node *get_current()
            {
                return current;
            }
        };
        PostorderIterator begin_postorder()
        {
            return PostorderIterator(root);
        }
        PostorderIterator end_postorder()
        {
            return PostorderIterator();
        }
        Node *first_node(const T &val)
        {
            
            for (auto it = begin_inorder(); it != end_inorder(); ++it)
            {
                 
                if (*it == val)
                {
                    return it.get_current();
                }
            }
            return nullptr;
        }
        BinaryTree<T> &add_root(const T &value)
        {
            if (!root)
            {
                this->root = new Node(value);
                return *this;
            }
            this->root->value = value;
            return *this;
        }
        BinaryTree<T> &add_left(const T &parent, const T &child)
        {
            if (!root)
            {
                throw std::invalid_argument("tree is empty, add a root first");
            }
            Node *place = first_node(parent);
            if (place)
            {
                
                if (!place->left)
                {
                    
                    Node *left_child = new Node(child);
                    left_child->parent = place;
                    place->left = left_child;
                    return *this;
                }
                place->left->value = child;
                return *this;
            }
            throw std::invalid_argument("no such elemnt in the tree!");
        }
        BinaryTree<T> &add_right(const T &parent, const T &child)
        {
            if (!root)
            {
                throw std::invalid_argument("tree is empty, add a root first");
            }
            Node *place = first_node(parent);
            
            if (place)
            {
                if (!place->right)
                {
                    Node *right_child = new Node(child);
                    right_child->parent = place;
                    place->right = right_child;
                    return *this;
                }
                place->right->value = child;
                return *this;
            }
            throw std::invalid_argument("no such elemnt in the tree!");
        }
        ~BinaryTree()
        {
            
            if (root)
            {
                for (auto it = begin_postorder(); it != end_postorder(); ++it)
                {
                    delete it.get_current();
                }
            }
        }
    };
}