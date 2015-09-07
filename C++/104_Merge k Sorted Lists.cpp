class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, nodeCmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL;
        while (!pq.empty()) {
            ListNode *frt = pq.top();
            pq.pop();
            if (head == NULL)
                head = frt;
            else
                pre->next = frt;
            pre = frt;
            if (frt->next != NULL)
                pq.push(frt->next);
        }
        return head;
    }

private:
    struct nodeCmp {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
};