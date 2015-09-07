class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode *now = head, *next;
        while (now != NULL) {
            next = new RandomListNode(now->label);
            next->next = now->next;
            now->next = next;
            now = next->next;
        }
        now = head;
        while (now != NULL) {
            now->next->random = now->random ? now->random->next : NULL;
            now = now->next->next;
        }
        RandomListNode *res = head->next;
        now = head;
        while (now != NULL) {
            next = now->next;
            now->next = next->next;
            next->next = next->next ? next->next->next : NULL;
            now = now->next;
        }
        return res;
    }
};