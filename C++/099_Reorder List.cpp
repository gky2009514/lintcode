class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return;
        stack<ListNode*> stk;
        ListNode *now = head;
        while (now != NULL) {
            stk.push(now);
            now = now->next;
        }
        ListNode *next = head->next;
        now = head;
        while (now != stk.top() && now->next != stk.top()) {
            ListNode *et = stk.top();
            stk.pop();
            now->next = et;
            et->next = next;
            now = next;
            next = now->next;
        }
        if (now == stk.top())
            now->next = NULL;
        else
            now->next->next = NULL;
    }
};