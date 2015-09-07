class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
     using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *mid = getMid(head);
        ListNode *rhead = mid->next;
        mid->next = NULL;
        ListNode *lhead = sortList(head);
        rhead = sortList(rhead);
        return merge(lhead, rhead);
    }

private:
    ListNode *getMid(ListNode *head) {
        ListNode *pre = NULL, *slow = head, *fast = head->next;
        while (fast != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
            fast = fast ? fast->next : NULL;
        }
        return pre;
    }

    ListNode *merge(ListNode *l, ListNode *r) {
        if (l == NULL || r == NULL)
            return l == NULL ? r : l;
        ListNode *now, *tail = NULL, *head = NULL;
        while (l != NULL && r != NULL) {
            if (l->val < r->val) {
                now = l;
                l = l->next;
            } else {
                now = r;
                r = r->next;
            }
            if (head == NULL) {
                head = tail = now;
            } else {
                tail->next = now;
                tail = now;
            }
        }
        while (l != NULL) {
            tail->next = l;
            tail = l;
            l = l->next;
        }
        while (r != NULL) {
            tail->next = r;
            tail = r;
            r = r->next;
        }
        return head;
    }
};