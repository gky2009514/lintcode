class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL)
            return l1 == NULL ? l2 : l1;
        ListNode *head = NULL, *tail = NULL;
        int sum, carry = 0;
        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            if (head == NULL) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            l1 = l1->next, l2 = l2->next;
        }
        while (l1) {
            sum = l1->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next, l1 = l1->next;
        }
        while (l2) {
            sum = l2->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next, l2 = l2->next;
        }
        if (carry)
            tail->next = new ListNode(carry);
        return head;
    }
};