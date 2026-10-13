class Solution {
public:
    // Helper function to create a deep copy of the list
    ListNode* copyList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* newHead = new ListNode(head->val);
        ListNode* currOld = head->next;
        ListNode* currNew = newHead;
        while (currOld != nullptr) {
            currNew->next = new ListNode(currOld->val);
            currOld = currOld->next;
            currNew = currNew->next;
        }
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // Reverse a COPY of head so the original list structure is preserved
        ListNode* temp = reverseList(copyList(head));
        ListNode* temp2 = head;

        while (temp != nullptr) {
            if (temp->val != temp2->val) {
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
};