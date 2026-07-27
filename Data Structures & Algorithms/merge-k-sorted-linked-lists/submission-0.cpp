/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        cout << lists.size() << '\n';
        for (int i = 0; i < lists.size(); i++)
        {
            while (lists[i])
            {
                pq.push(lists[i]);
                auto temp = lists[i]->next;
                lists[i]->next = nullptr;
                lists[i] = temp;
            }
        }

        ListNode* dummy = new ListNode(-1);
        auto tail = dummy;
        while(!pq.empty())
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
        }

        return dummy->next;
    }
};
