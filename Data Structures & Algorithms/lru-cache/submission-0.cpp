struct ListNode {
    int val;
    int key;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), key(0), next(nullptr), prev(nullptr) {}
    ListNode(int x, int y) : val(x), key(y), next(nullptr), prev(nullptr) {}
    ListNode(int x, int y, ListNode* next, ListNode* prev) : val(x), key(y), next(next), prev(prev) {}
};

class LRUCache {
public:
    unordered_map<int, ListNode*> mp;
    ListNode* head;
    ListNode* tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void promote(ListNode* node) {
        if (node == tail) return;

        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        node->next->prev = node->prev;

        node->prev = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        promote(mp[key]);
        return mp[key]->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->val = value;
            promote(mp[key]);
            return;
        }

        if ((int)mp.size() == capacity) {
            auto temp = head;
            mp.erase(temp->key);
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
            delete temp;
        }

        auto node = new ListNode(value, key);
        if (!head) { head = node; tail = node; }
        else { node->prev = tail; tail->next = node; tail = node; }
        mp[key] = node;
    }
};