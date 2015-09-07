class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        int len = getLen(head);
        k %= len;
        if (k == 0)
            return head;
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; i++)
            fast = fast->next;
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }

private:
    int getLen(ListNode *head) {
        int res = 0;
        while (head != NULL) {
            res++;
            head = head->next;
        }
        return res;
    }
};