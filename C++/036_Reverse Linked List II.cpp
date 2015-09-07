class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n)
            return head;
        ListNode *mpre = NULL, *nnext = NULL;
        ListNode *rtail = head;
        for (int i = 1; i < n; i++) {
            if (i == m - 1)
                mpre = rtail;
            rtail = rtail->next;
        }
        nnext = rtail->next;
        rtail->next = NULL;
        ListNode *rhead = mpre == NULL ? head : mpre->next;
        reverse(rhead, rtail);
        rtail->next = nnext;
        if (mpre) {
            mpre->next = rhead;
            return head;
        }
        return rhead;
    }

private:
    void reverse(ListNode *&head, ListNode *&tail) {
        ListNode *pre = NULL, *now = head, *next;
        while (now != NULL) {
            next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        tail = head;
        head = pre;
    }
};