class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int n = static_cast<int>(hashTable.size());
        int m = n << 1;
        vector<ListNode*> res(m, NULL);
        for (int i = 0; i < n; i++) {
            ListNode *lp = hashTable[i], *nt;
            while (lp != NULL) {
                nt = lp->next;
                int p = -1;
                if (lp->val < 0) {
                    int t = lp->val / m + 1;
                    p = (lp->val + t * m) % m;
                } else {
                    p = lp->val % m;
                }
                lp->next = NULL;
                if (res[p] == NULL) {
                    res[p] = lp;
                } else {
                    ListNode *rn = res[p];
                    while (rn->next != NULL)
                        rn = rn->next;
                    rn->next = lp;
                }
                lp = nt;
            }
        }
        return res;
    }
};