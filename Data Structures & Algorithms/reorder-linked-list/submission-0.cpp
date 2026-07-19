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
    void reorderList(ListNode* head) {
        if (!head->next) return;

        auto slow = head;
        auto fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        auto prev = slow->next;
        auto curr = prev->next;
        slow->next = nullptr; prev->next = nullptr;
        while (curr)
        {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        auto temp = head;
        while (temp && prev)
        {
            auto next = temp->next;
            temp->next = prev;
            temp = temp->next;
            prev = prev->next;
            temp->next = next;
            temp = temp->next;
        }
    }
};
