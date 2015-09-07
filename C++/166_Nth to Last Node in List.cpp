class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode *fast = head;
        while (n--)
            fast = fast->next;
        ListNode *slow = head;
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};