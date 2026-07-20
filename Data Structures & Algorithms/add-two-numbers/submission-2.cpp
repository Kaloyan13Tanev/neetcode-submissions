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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = (l1->val + l2->val) % 10;
        bool carry = (l1->val + l2->val) / 10;

        auto head = new ListNode(sum);
        auto temp = head;
        l1 = l1->next; l2 = l2->next;
        while (l1 && l2)
        {
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;

            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next; l2 = l2->next;
        }

        while (l1)
        {
            sum = (carry + l1->val) % 10;
            carry = (carry + l1->val) / 10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2)
        {
            sum = (carry + l2->val) % 10;
            carry = (carry + l2->val) / 10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l2 = l2->next;
        }

        if (!l1 && !l2 && carry) 
        {
            if (temp == head) head->next = new ListNode(1);
            else temp->next = new ListNode(1);
        } 
            
        return head;
    }
};
