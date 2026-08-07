
// Function to reverse the singly linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;  // 1. Store next node
        curr->next = prev;  // 2. Reverse current node's pointer
        prev = curr;        // 3. Move prev forward
        curr = next;        // 4. Move curr forward
    }

    return prev; // prev becomes the new head of the reversed list
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

