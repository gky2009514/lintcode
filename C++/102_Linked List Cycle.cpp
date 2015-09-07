class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast && fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : NULL;
        }
        return slow == fast;
    }
};