class Solution {
public:
    bool hasEnoughLeft(ListNode* start, int k)
    {
        auto copy = start;
        for (int i = 0; i < k; i++)
        {
            if (!copy) return false;
            copy = copy->next;
        }

        return true;
    }

    ListNode* reverseSection(ListNode* start, int k)
    {
        auto copy = start;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; i++)
        {
            auto next = copy->next;
            copy->next = prev;
            prev = copy;
            copy = next;
        }
        start->next = copy;

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        auto temp = head;
        ListNode dummy(-1);
        dummy.next = temp;
        auto prevSegm = &dummy;
        while (temp)
        {
            if (!hasEnoughLeft(temp, k)) break;

            prevSegm->next = reverseSection(temp, k);
            prevSegm = temp;
            temp = temp->next;
        }

        return dummy.next;
    }
};