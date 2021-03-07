/**
 * Design a data structure that follows the constraints of a Least Recently Used 
 * (LRU) cache.
 * 
 * Implement the LRUCache class:
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. 
 * Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
 * the capacity from this operation, evict the least recently used key.
 */

#include <iostream>
#include <unordered_map>

// structure to define node of the DLL (doubly linked-list)
struct Node {
    int key;
    int value;
    
    Node* next {nullptr};
    Node* prev {nullptr};
    
    Node() : key(-1), value(-1) {}
    Node(int key, int value) : key(key), value(value) {}
};

// DLL implementation
class List {
    Node* head {nullptr};
    Node* tail {nullptr};
    int len {0};
    
    public:
    Node* add_front(int key, int value) {
        Node* newNode {new Node(key, value)};
        
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++len;
        
        return newNode;
    }
    
    void del_front() {
        if(head) {
            if(head->next) {
                head->next->prev = nullptr;
                Node* n = head;
                head = head->next;
                delete n;
            } else {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            --len;
        }
    }
    
    Node del_back() {
        Node ret;
        if(tail) {
            ret = *tail;
            if(tail->prev) {
                Node* n = tail;
                tail->prev->next = nullptr;
                tail = tail->prev;
                delete n;
            } else {
                delete tail;
                tail = nullptr;
                head = nullptr;
            }
            --len;
        }
        return ret;
    }
    
    void remove(Node* ptr) {
        Node* n = ptr;
        if(n->prev) {
            n->prev->next = n->next;
        }
        if(n->next) {
            n->next->prev = n->prev;
        }
        if(head == n) {
            head = n->next;
        }
        if(tail == n) {
            tail = tail->prev;
        }
        
        delete ptr;
        --len;
    }
    
    int length() {
        return len;
    }
};

class LRUCache {
    std::unordered_map<int, Node*> hash;
    List lst;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        std::unordered_map<int, Node*>::iterator it;
        it = hash.find(key);
        if(it == hash.end()) {
            return -1;
        }
        // bring old entry of 'key' to front of the list - recently used
        int value = it->second->value;
        lst.remove(it->second);
        it->second = lst.add_front(key, value);
        return it->second->value;
    }
    
    void put(int key, int value) {
        std::unordered_map<int, Node*>::iterator it;
        it = hash.find(key);
        if(it != hash.end()) {
            // key already is present in the hash -
            // bring the node to front of the list & update its address in the hash
            lst.remove(it->second);
            it->second = lst.add_front(key, value);
        }
        else {
            if(lst.length() == capacity) {
                Node n = lst.del_back();
                if(n.key != -1) hash.erase(n.key);
            }
            // insert new pair<key, value>
            hash.insert(std::pair<int, Node*>(key, lst.add_front(key, value)));
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* obj = new LRUCache(3);
    std::cout << "Get 1 : "  << obj->get(1) << "\n";
    obj->put(1, 2);
    obj->put(2, 3);
    obj->put(3, 4);
    obj->put(1, 5);
    obj->put(5, 6);
    std::cout << "Get 1 : "  << obj->get(1) << "\n";
    std::cout << "Get 2 : "  << obj->get(2) << "\n";
    std::cout << "Get 5 : "  << obj->get(5) << "\n";
    return 0;
}