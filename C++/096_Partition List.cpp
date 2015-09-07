class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *frhead = NULL, *frtail = NULL;
        ListNode *sehead = NULL, *setail = NULL;
        while (head != NULL) {
            if (head->val < x) {
                if (frhead == NULL) {
                    frhead = frtail = head;
                } else {
                    frtail->next = head;
                    frtail = head;
                }
            } else {
                if (sehead == NULL) {
                    sehead = setail = head;
                } else {
                    setail->next = head;
                    setail = head;
                }
            }
            head = head->next;
        }
        if (frhead == NULL)
            return sehead;
        frtail->next = sehead;
        if (setail)
            setail->next = NULL;
        return frhead;
    }
};