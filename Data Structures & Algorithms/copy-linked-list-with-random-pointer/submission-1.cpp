/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;
        mp[head] = new Node(head->val);
        auto temp = head;

        while (temp)
        {
            if (mp.find(temp->next) == mp.end())
                mp[temp->next] = new Node(temp->next->val);
            
            mp[temp]->next = mp[temp->next];

            if (mp.find(temp->random) == mp.end())
                mp[temp->random] = new Node(temp->random->val);

            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};
