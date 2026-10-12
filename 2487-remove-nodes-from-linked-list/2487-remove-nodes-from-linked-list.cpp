class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;

        // Post-order recursion
        head->next = removeNodes(head->next);

        // If current value is smaller than next, discard current node
        if (head->val < head->next->val) {
            return head->next;
        }
        return head;
    }
};