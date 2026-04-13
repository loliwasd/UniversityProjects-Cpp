#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class TreeNode {
public:
    int key;
    std::string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k, const std::string& v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, int key, const std::string& value) {
        if (!node) return new TreeNode(key, value);
        if (key < node->key) {
            node->left = insertHelper(node->left, key, value);
        } else if (key > node->key) {
            node->right = insertHelper(node->right, key, value);
        }
        return node;
    }

    TreeNode* deleteHelper(TreeNode* node, int key) {
        if (!node) return nullptr;
        
        if (key < node->key) {
            node->left = deleteHelper(node->left, key);
        } else if (key > node->key) {
            node->right = deleteHelper(node->right, key);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = node->right;
            while (temp->left) temp = temp->left;
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteHelper(node->right, temp->key);
        }
        return node;
    }

    void storeNodesInOrder(TreeNode* node, std::vector<TreeNode*>& nodes) {
        if (!node) return;
        storeNodesInOrder(node->left, nodes);
        nodes.push_back(node);
        storeNodesInOrder(node->right, nodes);
    }

    TreeNode* buildBalancedTree(std::vector<TreeNode*>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* node = nodes[mid];
        node->left = buildBalancedTree(nodes, start, mid - 1);
        node->right = buildBalancedTree(nodes, mid + 1, end);
        return node;
    }

    void destroyTree(TreeNode* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    void preOrderHelper(TreeNode* node) {
        if (!node) return;
        std::cout << node->key << ": " << node->value << std::endl;
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }

    void postOrderHelper(TreeNode* node) {
        if (!node) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->key << ": " << node->value << std::endl;
    }

    void inOrderHelper(TreeNode* node) {
        if (!node) return;
        inOrderHelper(node->left);
        std::cout << node->key << ": " << node->value << std::endl;
        inOrderHelper(node->right);
    }

    int countTwoChildrenHelper(TreeNode* node) {
        if (!node) return 0;
        int count = (node->left && node->right) ? 1 : 0;
        return count + countTwoChildrenHelper(node->left) 
                   + countTwoChildrenHelper(node->right);
    }

public:
    BST() : root(nullptr) {}
    ~BST() { destroyTree(root); }

    void loadFromArray(const std::vector<std::pair<int, std::string>>& data) {
        for (const auto& item : data) {
            insert(item.first, item.second);
        }
    }

    void insert(int key, const std::string& value) {
        root = insertHelper(root, key, value);
    }

    void remove(int key) {
        root = deleteHelper(root, key);
    }

    TreeNode* search(int key) {
        TreeNode* current = root;
        while (current) {
            if (key == current->key) return current;
            current = (key < current->key) ? current->left : current->right;
        }
        return nullptr;
    }
    void balanceTree() {
        std::vector<TreeNode*> nodes;
        storeNodesInOrder(root, nodes);
        root = buildBalancedTree(nodes, 0, nodes.size() - 1);
    }

    void printPreOrder() {
        std::cout << "Pre-order traversal:" << std::endl;
        preOrderHelper(root);
    }

    void printPostOrder() {
        std::cout << "Post-order traversal:" << std::endl;
        postOrderHelper(root);
    }

    void printInOrder() {
        std::cout << "In-order traversal:" << std::endl;
        inOrderHelper(root);
    }

    int countNodesWithTwoChildren() {
        return countTwoChildrenHelper(root);
    }
};

int main() {
    BST tree;

    std::vector<std::pair<int, std::string>> data = {
        {50, "Иванов И.И."},
        {30, "Петров П.П."},
        {70, "Сидоров С.С."},
        {20, "Смирнов А.А."},
        {40, "Кузнецов Д.В."},
        {60, "Васильева Е.П."},
        {80, "Николаева О.К."}
    };

    tree.loadFromArray(data);

    tree.printInOrder();
    tree.printPreOrder();
    tree.printPostOrder();

    std::cout << "\nБалансировка дерева..." << std::endl;
    tree.balanceTree();
    tree.printInOrder();

    int searchKey = 40;
    TreeNode* found = tree.search(searchKey);
    if (found) {
        std::cout << "\nНайден элемент с ключом " << searchKey 
                  << ": " << found->value << std::endl;
    }

    int deleteKey = 50;
    std::cout << "\nУдаление элемента с ключом " << deleteKey << std::endl;
    tree.remove(deleteKey);
    tree.printInOrder();

    std::cout << "\nУзлов с двумя дочерьми: " 
              << tree.countNodesWithTwoChildren() << std::endl;

    std::cout << "\nДобавление нового элемента (45, 'Новиков Р.С.')" << std::endl;
    tree.insert(45, "Новиков Р.С.");
    tree.printInOrder();

    return 0;
}