
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
            Node *right, *left, *father;
            Node(const T &val) : value(val), right(nullptr), left(nullptr), father(nullptr) {}
            ~Node() {}
        };
        Node *root; //member of the tree
        static void update_node(Node *root, const T &val) { root->value = val; }
        static Node *find(Node *root, const T &val)
        {

            if (root == nullptr)
                return nullptr;
            if (root->value == val)
            {
                return root;
            }
            Node *possible_ans = find(root->left, val);
            if (possible_ans == nullptr)
            {
                possible_ans = find(root->right, val);
            }

            return possible_ans;
        }
        static Node most_left_son(Node *root)
        {
            Node curr = *root;
            *root = *root->left;
            while (root != nullptr)
            {
                Node curr = *root;
                *root = *root->left;
            }
            return curr;
        }
        static bool is_left_son(Node *node)
        {
            if (*node->father == nullptr)
                return false;
            Node father = *node->father;
            return father->left == *node;
        }
        static Node *get_ancestor(Node *node)
        {
            Node *father = node->father;
            while (father != nullptr && father->right == node)
            {
                node = father;
                father = father->father;
            }
            return father;
        }

    public:
        BinaryTree()
        {

            this->root = nullptr;
        }
        ~BinaryTree() {}
        friend std::ostream &operator<<(std::ostream &stream, const BinaryTree<T> &tree) { return stream; }
        /* add / update root */
        BinaryTree &add_root(const T &val)
        {
            if (this->root == nullptr)
            {
                Node new_root(val);
                this->root = &new_root;
            }
            else
            {
                update_node(this->root, val);
            }

            return *this;
        }

        BinaryTree &add_left(const T &val, const T &child)
        {

            Node *place = find(root, val);
            if (place == nullptr)
                throw std::invalid_argument("No such value in the tree");
            if (place->left == nullptr)
            {
                Node new_node(child);
                *place->left = new_node;
            }
            else
            {
                update_node(place->left, child);
            }
            return *this;
        }
        BinaryTree &add_right(const T &val, const T &child)
        {
            Node *place = find(root, val);

            if (place == nullptr)
                throw std::invalid_argument("No such value in the tree");
            if (place->right == nullptr)
            {

                Node right_node(child);
                *place->right = right_node;
            }
            else
            {
                update_node(place->right, child);
            }
            return *this;
        }

        T &operator*() const { return this->root->value; }
        T *operator->() const
        {
            T value;
            return value;
        }
        class preorder_iterator
        {
        private:
            Node *current_node;

        public:
            preorder_iterator(Node *ptr = nullptr) : current_node(ptr) {}
            T &operator*() const { return current_node->value; }
            preorder_iterator &operator++()
            {
                if (current_node->left != nullptr)
                    current_node = current_node->left;
                if (current_node->right != nullptr)
                    current_node = current_node->right;
                Node *ancestor = get_ancestor(current_node);
                if (ancestor == nullptr)
                    current_node = nullptr;
                else
                {
                    current_node = ancestor->right;
                }
                return *this;
            }
            //prefix
            preorder_iterator operator++(int) { return *this; } //postfix
            bool operator==(const preorder_iterator &it) const { return false; }
            bool operator!=(const preorder_iterator &it) const { return false; }
            preorder_iterator &operator=(const preorder_iterator &iterator) { return iterator; }
            T *operator->() const
            {
                T ans;
                return this->current_node->value;
            }

            int size() { return 0; }
        };
        class inorder_iterator
        {
        private:
            Node *current_node;

        public:
            inorder_iterator(Node *ptr = nullptr) : current_node(ptr) {}
            T &operator*() const { return current_node->value; }
            inorder_iterator &operator++() { return *this; }   //prefox
            inorder_iterator operator++(int) { return *this; } //postfix
            bool operator==(const inorder_iterator &it) const { return false; }
            bool operator!=(const inorder_iterator &it) const { return false; }
            inorder_iterator &operator=(const inorder_iterator &iterator) { return iterator; }
            T *operator->() const
            {
                T ans;
                return ans;
            }
            int size() { return 0; }
        };
        class postorder_iterator
        {
        private:
            Node *current_node;

        public:
            postorder_iterator() : current_node(nullptr) {}
            T &operator*() const { return current_node->value; }
            postorder_iterator &operator++() { return *this; }   //prefox
            postorder_iterator operator++(int) { return *this; } //postfix
            bool operator==(const postorder_iterator &it) const { return false; }
            bool operator!=(const postorder_iterator &it) const { return false; }
            postorder_iterator &operator=(const postorder_iterator &iterator) { return iterator; }
            T *operator->() const
            {
                return nullptr;
            }
            int size() { return 0; }
        };
        inorder_iterator begin() { return inorder_iterator(); }
        inorder_iterator end() { return inorder_iterator(); }
        inorder_iterator begin_inorder()
        {

            return inorder_iterator();
        }
        inorder_iterator end_inorder() { return inorder_iterator(); }
        preorder_iterator begin_preorder()
        {
            return preorder_iterator(this->root);
        }
        preorder_iterator end_preorder() { return preorder_iterator(); }
        postorder_iterator begin_postorder() { return postorder_iterator(); }
        postorder_iterator end_postorder() { return postorder_iterator(); }
    };
}