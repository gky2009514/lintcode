class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
        free(next);
    }
};