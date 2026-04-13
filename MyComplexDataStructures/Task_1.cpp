#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

class BST {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    
    Node* addHelper(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->value) {
            node->left = addHelper(node->left, value);
        } else {
            node->right = addHelper(node->right, value);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* removeHelper(Node* node, int value) {
        if (!node) return nullptr;
        
        if (value < node->value) {
            node->left = removeHelper(node->left, value);
        } else if (value > node->value) {
            node->right = removeHelper(node->right, value);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = removeHelper(node->right, temp->value);
        }
        return node;
    }

    Node* findHelper(Node* node, int value) {
        if (!node || node->value == value) return node;
        return (value < node->value) ? findHelper(node->left, value) 
                                    : findHelper(node->right, value);
    }

    void traverseHelper(Node* node, std::vector<int>& result) {
        if (!node) return;
        traverseHelper(node->left, result);
        result.push_back(node->value);
        traverseHelper(node->right, result);
    }

    Node* insertSubtree(Node* target, Node* subtree) {
        if (!target) return subtree;
        if (subtree->value < target->value) {
            target->left = insertSubtree(target->left, subtree);
        } else {
            target->right = insertSubtree(target->right, subtree);
        }
        return target;
    }

    Node* deleteBranch(Node* node, int value) {
        if (!node) return nullptr;
        if (node->value == value) {
            destroyTree(node);
            return nullptr;
        }
        node->left = deleteBranch(node->left, value);
        node->right = deleteBranch(node->right, value);
        return node;
    }

    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    Node* findLCA(Node* node, int a, int b) {
        if (!node) return nullptr;
        if (node->value > a && node->value > b)
            return findLCA(node->left, a, b);
        if (node->value < a && node->value < b)
            return findLCA(node->right, a, b);
        return node;
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroyTree(root); }

    void add(int value) {
        root = addHelper(root, value);
    }

    void remove(int value) {
        root = removeHelper(root, value);
    }

    bool find(int value) {
        return findHelper(root, value) != nullptr;
    }

    std::vector<int> traverse() {
        std::vector<int> result;
        traverseHelper(root, result);
        return result;
    }

    void insertSubtreeAt(int targetValue, BST& subtree) {
        Node* target = findHelper(root, targetValue);
        root = insertSubtree(target, subtree.root);
        subtree.root = nullptr;
    }

    void deleteBranch(int branchRootValue) {
        root = deleteBranch(root, branchRootValue);
    }
    void insertAtPosition(int parentValue, int newValue, bool asLeftChild) {
        Node* parent = findHelper(root, parentValue);
        if (!parent) return;
        
        Node*& childPtr = asLeftChild ? parent->left : parent->right;
        if (childPtr) deleteBranch(childPtr->value);
        childPtr = new Node(newValue);
    }

    int findLCA(int a, int b) {
        Node* lca = findLCA(root, a, b);
        return lca ? lca->value : -1;
    }

    void printTree() {
        std::cout << "Tree structure:\n";
        std::queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                Node* current = q.front();
                q.pop();
                if (current) {
                    std::cout << current->value << " ";
                    q.push(current->left);
                    q.push(current->right);
                } else {
                    std::cout << "null ";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    BST tree;
    
    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);
    
    std::cout << "Original tree:\n";
    tree.printTree();
    
    tree.remove(20);
    std::cout << "\nAfter removing 20:\n";
    tree.printTree();
    
    BST subtree;
    subtree.add(35);
    subtree.add(25);
    subtree.add(45);
    tree.insertSubtreeAt(30, subtree);
    std::cout << "\nAfter inserting subtree at 30:\n";
    tree.printTree();
    
    std::cout << "\nLCA of 25 and 45: " << tree.findLCA(25, 45) << std::endl;
    
    return 0;
}