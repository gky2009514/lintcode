class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = head, *now = head->next;
        while (now != NULL) {
            if (now->val == pre->val)
                pre->next = now->next;
            else
                pre = now;
            now = now->next;
        }
        return head;
    }
};