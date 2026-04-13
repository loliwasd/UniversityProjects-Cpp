#include <string>
#include <vector>
#include <iostream>

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

    TreeNode* insertHelper(TreeNode* node, int key, const std::string& value);
    TreeNode* deleteHelper(TreeNode* node, int key);
    void destroyTree(TreeNode* node);
    void inOrderTraversal(TreeNode* node);

public:
    BST() : root(nullptr) {}
    ~BST() { destroyTree(root); }

    void loadFromArray(const std::vector<std::pair<int, std::string>>& data);
    void balanceTree();
    void insert(int key, const std::string& value);
    TreeNode* search(int key);
    void remove(int key);
    void printPreOrder();
    void printPostOrder();
    void printInOrder();
    void storeNodesInOrder(TreeNode* node, std::vector<TreeNode*>& nodes);
    int countNodesWithTwoChildrenHelper(TreeNode* node);
    int countNodesWithTwoChildren();
    TreeNode* buildBalancedTree(std::vector<TreeNode*>& nodes, int start, int end);
};

void BST::loadFromArray(const std::vector<std::pair<int, std::string>>& data) {
    for (const auto& item : data) {
        insert(item.first, item.second);
    }
}

TreeNode* BST::insertHelper(TreeNode* node, int key, const std::string& value) {
    if (!node) return new TreeNode(key, value);
    if (key < node->key) {
        node->left = insertHelper(node->left, key, value);
    } else if (key > node->key) {
        node->right = insertHelper(node->right, key, value);
    }
    return node;
}

void BST::insert(int key, const std::string& value) {
    root = insertHelper(root, key, value);
}

TreeNode* BST::deleteHelper(TreeNode* node, int key) {
    if (!node) return nullptr;
    
    if (key < node->key) {
        node->left = deleteHelper(node->left, key);
    } else if (key > node->key) {
        node->right = deleteHelper(node->right, key);
    } else {
        // Узел с одним потомком или без
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        // Узел с двумя потомками: находим минимальный в правом поддереве
        TreeNode* temp = node->right;
        while (temp->left) temp = temp->left;
        node->key = temp->key;
        node->value = temp->value;
        node->right = deleteHelper(node->right, temp->key);
    }
    return node;
}

void BST::remove(int key) {
    root = deleteHelper(root, key);
}

void BST::printInOrder() {
    inOrderTraversal(root);
    std::cout << std::endl;
}

void BST::inOrderTraversal(TreeNode* node) {
    if (!node) return;
    inOrderTraversal(node->left);
    std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
    inOrderTraversal(node->right);
}

int BST::countNodesWithTwoChildrenHelper(TreeNode* node) {
    if (!node) return 0;
    int count = (node->left && node->right) ? 1 : 0;
    return count + countNodesWithTwoChildrenHelper(node->left) 
                + countNodesWithTwoChildrenHelper(node->right);
}

int BST::countNodesWithTwoChildren() {
    return countNodesWithTwoChildrenHelper(root);
}

void BST::storeNodesInOrder(TreeNode* node, std::vector<TreeNode*>& nodes) {
    if (!node) return;  // Базовый случай рекурсии
    
    // Рекурсивный обход: левое поддерево → корень → правое поддерево
    storeNodesInOrder(node->left, nodes);
    nodes.push_back(node);  // Сохраняем текущий узел
    storeNodesInOrder(node->right, nodes);
}

void BST::balanceTree() {
    std::vector<TreeNode*> nodes;
    storeNodesInOrder(root, nodes); // Сохраняем узлы в отсортированном порядке
    root = buildBalancedTree(nodes, 0, nodes.size() - 1);
}

TreeNode* BST::buildBalancedTree(std::vector<TreeNode*>& nodes, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* node = nodes[mid];
    node->left = buildBalancedTree(nodes, start, mid - 1);
    node->right = buildBalancedTree(nodes, mid + 1, end);
    return node;
}

int main() {
    BST tree;
    std::vector<std::pair<int, std::string>> data = {
        {50, "Иванов И.И."},
        {30, "Петров П.П."},
        {70, "Сидоров С.С."}
    };
    tree.loadFromArray(data);
    tree.insert(40, "Смирнов А.А.");
    TreeNode* found = tree.search(30);
    if (found) std::cout << "Найдено: " << found->value << std::endl;
    tree.remove(50);
    std::cout << "Прямой обход:" << std::endl;
    tree.printPreOrder();
    tree.balanceTree();
    std::cout << "Узлов с двумя дочерьми: " << tree.countNodesWithTwoChildren() << std::endl;

    return 0;
}