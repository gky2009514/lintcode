class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = NULL, *now = head, *next = head;
        while (next != NULL) {
            now = next;
            next = now->next;
            now->next = pre;
            pre = now;
        }
        return now;
    }
};