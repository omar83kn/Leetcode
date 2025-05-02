#include <unordered_map>

class LRUCache {
private:
    // Node structure for doubly linked list
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity; // Maximum number of key-value pairs
    std::unordered_map<int, Node*> cache; // Maps key to node in doubly linked list
    Node* head; // Dummy head (most recent side)
    Node* tail; // Dummy tail (least recent side)
    
    // Add node right after head (most recent)
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    // Remove node from doubly linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // Move node to front (most recent)
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }
    
    // Remove least recent node (tail->prev) and return its key
    int removeLRU() {
        Node* lru = tail->prev;
        int key = lru->key;
        removeNode(lru);
        delete lru;
        return key;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        Node* node = cache[key];
        moveToFront(node); // Mark as most recent
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists: update value and move to front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            // New key: create node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            
            // If over capacity, remove LRU
            if (cache.size() > capacity) {
                int lruKey = removeLRU();
                cache.erase(lruKey);
            }
        }
    }
    
    // Destructor to clean up memory
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};