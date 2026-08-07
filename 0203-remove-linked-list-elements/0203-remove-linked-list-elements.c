#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Dummy node handles head deletions automatically
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* curr = &dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            // Save matching node, unlink it, and free memory
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            // Only advance curr when no deletion happens
            curr = curr->next;
        }
    }

    return dummy.next;
}