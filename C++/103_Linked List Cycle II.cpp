class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && slow != fast) {
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : fast;
        }
        if (fast == NULL)
            return NULL;
        slow = head, fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};