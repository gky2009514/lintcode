class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *now = head->next, *next = head->next->next;
        head->next = NULL;
        while (now != NULL) {
            if (now->val <= head->val) {
                now->next = head;
                head = now;
            } else {
                ListNode *p = head, *pre = head;
                while (p && p->val < now->val) {
                    pre = p;
                    p = p->next;
                }
                pre->next = now;
                now->next = p;
            }
            now = next;
            next = now ? now->next : NULL;
        }
        return head;
    }
};