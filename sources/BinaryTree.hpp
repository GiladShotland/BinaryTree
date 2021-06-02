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
            Node *right, *left, *father; //father pointer for navigating in the tree
            Node(const T &val) : value(val) {}
            ~Node() {}
        };
        Node *root; //node root of the tree
        void remove_nodes(Node *root){
            if(root == nullptr) return;
            remove_nodes(root->left);
            remove_nodes(root->right);
            delete root;
        }
        Node *find(Node *root,const T &val){
            if(root == nullptr) return nullptr;
            if(root->value == val){return root;}
            Node *ans = find(root->left,val);
            if(ans != nullptr) return ans;
            return find(root->right,val); 
        }
        Node *most_left(Node *root){
            if(!root->left){
                return root; 
            }
            return most_left(root);
        }

    public:
        BinaryTree()
        {

            this->root = nullptr;
        }
        BinaryTree( const BinaryTree<T> &toCopy){
            this->root = nullptr;
        }
        ~BinaryTree() {
            remove_nodes(this->root);
        }
        friend std::ostream &operator<<(std::ostream &stream, const BinaryTree<T> &tree) { return stream; }
        BinaryTree &add_root(const T &val){
            if(this->root == nullptr){
                Node *r = new Node{val};
                this->root = r;
                return *this;
            }
            this->root->value = val;
            return *this;}
        BinaryTree &add_left(const T &val, const T &child){
            Node *current = find(this->root,child);
            if(current){
                current->value = child;
                return *this;
            }
            Node *parent = find(this->root,val);
            if(parent){
                Node *son = new Node{child};
                parent->left = son;
                return *this;
            }
            throw std::invalid_argument("parent element didnt found");
        }
        BinaryTree &add_right(const T &val, const T &child){
            Node *current = find(this->root,child);
            if(current){
                current->value = child;
                return *this;
            }
            Node *parent = find(this->root,val);
            if(parent){
                Node *son = new Node{child};
                parent->right = son;
                return *this;
            }
            throw std::invalid_argument("parent element didnt found");
            
            }
        
        class inorder_iterator
        {
        private:
            Node *current_node;

        public:
            inorder_iterator(Node *ptr = nullptr) : current_node(ptr) {}
            T &operator*() const { return current_node->value; }
            inorder_iterator &operator++() { return *this; }   //prefox
            inorder_iterator &operator++(int) { return *this; } //postfix
            bool operator==(const inorder_iterator &it) const { return false; }
            bool operator!=(const inorder_iterator &it) const { return false; }
            inorder_iterator &operator=(const inorder_iterator &iterator) { return *this; }
            T *operator->() const
            {
                
                return &(current_node->value);
            }
        };
        class preorder_iterator
        {
        private:
            Node *current_node;

        public:
            preorder_iterator(Node *ptr = nullptr) : current_node(ptr) {}
            T &operator*() const { return current_node->value; }
            preorder_iterator &operator++(){ 
                return *this;   }
            preorder_iterator &operator++(int) { return *this; } 
            bool operator==(const preorder_iterator &it) const { return false; }
            bool operator!=(const preorder_iterator &it) const { return false; }
            preorder_iterator &operator=(const preorder_iterator &iterator) { return *this; }
            T *operator->() const
            {
                return &(current_node->value);
            }
        };
        
        class postorder_iterator
        {
        private:
            Node *current_node;

        public:
            postorder_iterator() : current_node(nullptr) {}
            T &operator*() const { return current_node->value; }
            postorder_iterator &operator++() { return *this; }   //prefix
            postorder_iterator &operator++(int) { return *this; } //postfix
            bool operator==(const postorder_iterator &it) const { return false; }
            bool operator!=(const postorder_iterator &it) const { return false; }
            postorder_iterator &operator=(const postorder_iterator &iterator) { return *this; }
            T *operator->() const
            {
                 return &(current_node->value);
            }
        };
        inorder_iterator begin() { return inorder_iterator(most_left(this->root)); }
        inorder_iterator end() { return inorder_iterator(); }
        inorder_iterator begin_inorder()
        { return inorder_iterator(most_left(this->root));}
        inorder_iterator end_inorder() { return inorder_iterator(); }
        preorder_iterator begin_preorder(){return preorder_iterator(this->root);}
        preorder_iterator end_preorder() { return preorder_iterator(); }
        postorder_iterator begin_postorder() { return postorder_iterator(most_left(this->root)); }
        postorder_iterator end_postorder() { return postorder_iterator(); }
    };
}