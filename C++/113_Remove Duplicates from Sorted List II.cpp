class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        ListNode *rhead = NULL, *rtail = NULL;
        ListNode *now = head;
        while (now) {
            now = findNext(now);
            if (rhead == NULL) {
                rhead = rtail = now;
            } else {
                rtail->next = now;
                rtail = now;
            }
            now = now ? now->next : NULL;
        }
        if (rtail)
            rtail->next = NULL;
        return rhead;
    }

private:
    ListNode *findNext(ListNode *head) {
        ListNode *st = head, *ed = head->next;
        while (st && ed) {
            while (ed && st->val == ed->val)
                ed = ed->next;
            if (ed == NULL)
                return NULL;
            if (ed == st->next)
                return st;
            st = ed, ed = st->next;
        }
        return st;
    }
};