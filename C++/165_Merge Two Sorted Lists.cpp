class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL)
            return l1 == NULL ? l2 : l1;
        ListNode *head = NULL, *pre = NULL;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (pre == NULL) {
                    head = pre = l1;
                } else {
                    pre->next = l1;
                    pre = l1;
                }
                l1 = l1->next;
            } else {
                if (pre == NULL) {
                    head = pre = l2;
                } else {
                    pre->next = l2;
                    pre = l2;
                }
                l2 = l2->next;
            }
        }
        if (l1 || l2)
            pre->next = l1 ? l1 : l2;
        return head;
    }
};