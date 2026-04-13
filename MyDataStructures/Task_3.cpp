#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class HashTableBase {
protected:
    struct Node {
        int key;
        std::string value;
        Node* next;
        Node(int k, const std::string& v) : key(k), value(v), next(nullptr) {}
    };

    struct Stack {
        Node* top;
        Stack() : top(nullptr) {}
    };

    static const int TABLE_SIZE = 10;
    Stack* table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTableBase() {
        table = new Stack[TABLE_SIZE];
    }

    virtual ~HashTableBase() {
        clearTable();
        delete[] table;
    }

    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index].top;
        table[index].top = newNode;
    }

    virtual bool remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index].top;
        Node* prev = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev)
                    prev->next = current->next;
                else
                    table[index].top = current->next;
                
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    std::string search(int key) {
        int index = hashFunction(key);
        Node* current = table[index].top;
        
        while (current) {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        return "Not found";
    }

    void clearTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            while (table[i].top) {
                Node* temp = table[i].top;
                table[i].top = table[i].top->next;
                delete temp;
            }
        }
    }

    virtual void print() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Bucket " << i << ": ";
            Node* current = table[i].top;
            while (current) {
                std::cout << "[" << current->key << ": " << current->value << "] ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

class HashTableExtended : public HashTableBase {
public:
    void removeEvenKeys() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i].top;
            Node* prev = nullptr;

            while (current) {
                if (current->key % 2 == 0) {
                    Node* toDelete = current;
                    if (prev)
                        prev->next = current->next;
                    else
                        table[i].top = current->next;
                    
                    current = current->next;
                    delete toDelete;
                } else {
                    prev = current;
                    current = current->next;
                }
            }
        }
    }
};

int main() {
    srand(time(0));
    HashTableExtended ht;

    for (int i = 0; i < 20; ++i) {
        int key = rand() % 100;
        ht.insert(key, "Value" + std::to_string(key));
    }

    std::cout << "Initial Hash Table:" << std::endl;
    ht.print();

    ht.removeEvenKeys();

    std::cout << "\nHash Table after removing even keys:" << std::endl;
    ht.print();
    std::cout << "\nSearching for key 50: " << ht.search(50) << std::endl;
    ht.insert(50, "NewValue50");
    std::cout << "After insertion: " << ht.search(50) << std::endl;
    ht.remove(50);
    std::cout << "After removal: " << ht.search(50) << std::endl;

    return 0;
}