#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <stdexcept>

class ArrayHeap {
private:
    struct Node {
        int value;
        std::weak_ptr<Node> parent;
        
        Node(int val) : value(val) {}
    };

    std::vector<std::shared_ptr<Node>> heap;

    void heapifyUp(int index) {
        if (index == 0) return;
        
        int parentIndex = (index - 1) / 2;
        if (heap[index]->value > heap[parentIndex]->value) {
            std::swap(heap[index], heap[parentIndex]);
            heap[index]->parent = heap[parentIndex];
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left]->value > heap[largest]->value)
            largest = left;
            
        if (right < heap.size() && heap[right]->value > heap[largest]->value)
            largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heap[index]->parent = heap[largest];
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        auto newNode = std::make_shared<Node>(value);
        if (!heap.empty()) {
            newNode->parent = heap[(heap.size() - 1) / 2];
        }
        heap.push_back(newNode);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) throw std::runtime_error("Heap is empty");
        
        int max = heap[0]->value;
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return max;
    }

    void print() const {
        std::cout << "Array Heap: [ ";
        for (const auto& node : heap) {
            std::cout << node->value << " ";
        }
        std::cout << "]\n";
    }
};

class ListHeap {
private:
    struct Node {
        int value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        
        Node(int val) : value(val) {}
    };

    std::shared_ptr<Node> root;
    std::queue<std::weak_ptr<Node>> insertionQueue;

    void heapifyUp(std::shared_ptr<Node> node) {
        auto parent = node->parent.lock();
        if (!parent) return;
        
        if (node->value > parent->value) {
            std::swap(node->value, parent->value);
            heapifyUp(parent);
        }
    }

    void heapifyDown(std::shared_ptr<Node> node) {
        auto largest = node;
        
        if (node->left && node->left->value > largest->value)
            largest = node->left;
            
        if (node->right && node->right->value > largest->value)
            largest = node->right;

        if (largest != node) {
            std::swap(node->value, largest->value);
            heapifyDown(largest);
        }
    }

public:
    ListHeap() : root(nullptr) {}

    void insert(int value) {
        auto newNode = std::make_shared<Node>(value);
        
        if (!root) {
            root = newNode;
            insertionQueue.push(newNode);
            return;
        }

        auto nextParent = insertionQueue.front().lock();
        if (!nextParent->left) {
            nextParent->left = newNode;
            newNode->parent = nextParent;
        } else {
            nextParent->right = newNode;
            newNode->parent = nextParent;
            insertionQueue.pop();
        }
        
        insertionQueue.push(newNode);
        heapifyUp(newNode);
    }

    int extractMax() {
        if (!root) throw std::runtime_error("Heap is empty");
        
        int max = root->value;
        auto lastNode = insertionQueue.back().lock();
        insertionQueue.pop();
        
        if (lastNode == root) {
            root.reset();
            return max;
        }root->value = lastNode->value;
        auto parent = lastNode->parent.lock();
        
        if (parent->left == lastNode) {
            parent->left.reset();
        } else {
            parent->right.reset();
        }
        
        heapifyDown(root);
        return max;
    }

    void print() const {
        std::cout << "List Heap: [ ";
        std::queue<std::shared_ptr<Node>> q;
        if (root) q.push(root);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            std::cout << node->value << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        std::cout << "]\n";
    }
};

int main() {
    ArrayHeap arrHeap;
    arrHeap.insert(10);
    arrHeap.insert(20);
    arrHeap.insert(5);
    arrHeap.insert(30);
    arrHeap.print();
    
    std::cout << "Extracted max: " << arrHeap.extractMax() << "\n";
    arrHeap.print();

    ListHeap listHeap;
    listHeap.insert(10);
    listHeap.insert(20);
    listHeap.insert(5);
    listHeap.insert(30);
    listHeap.print();
    
    std::cout << "Extracted max: " << listHeap.extractMax() << "\n";
    listHeap.print();

    return 0;
}