class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;

        for (auto cur = head; cur; cur = cur->next) {
            if (!mp.count(cur)) mp[cur] = new Node(cur->val);
            if (!mp.count(cur->next)) mp[cur->next] = new Node(cur->next->val);
            if (!mp.count(cur->random)) mp[cur->random] = new Node(cur->random->val);

            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
        }
        return mp[head];
    }
};