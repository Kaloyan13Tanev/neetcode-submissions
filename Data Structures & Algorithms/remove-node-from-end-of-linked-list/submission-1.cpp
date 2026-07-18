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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        auto temp = head;
        while (temp)
        {
            size++; temp = temp->next;
        }

        int index = size - n;
        if (index == 0) 
        {
            head = head->next;
            return head;
        }
        
        temp = head;
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};
