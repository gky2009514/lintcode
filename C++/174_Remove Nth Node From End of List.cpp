class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n <= 0)
            return head;
        ListNode *fast = head, *slow = head, *pre = NULL;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (pre != NULL) {
            pre->next = slow->next;
            return head;
        } else {
            return head->next;
        }
    }
};