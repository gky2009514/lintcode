class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        int len = getLen(head);
        vector<ListNode*> listpt(len, NULL);
        listpt[0] = head;
        for (int i = 1; i < len; i++)
            listpt[i] = listpt[i - 1]->next;
        return genBST(0, len - 1, listpt);
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
    
    TreeNode *genBST(int l, int r, const vector<ListNode*> &listpt) {
        if (l > r)
            return NULL;
        if (l == r) {
            TreeNode *node = new TreeNode(listpt[l]->val);
            return node;
        }
        int mid = l + ((r - l) >> 1);
        TreeNode *node = new TreeNode(listpt[mid]->val);
        node->left = genBST(l, mid - 1, listpt);
        node->right = genBST(mid + 1, r, listpt);
        return node;
    }
};