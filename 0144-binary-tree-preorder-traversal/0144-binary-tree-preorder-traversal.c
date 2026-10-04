/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void preorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    result[(*returnSize)++] = root->val;
    preorderHelper(root->left, result, returnSize);
    preorderHelper(root->right, result, returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int *)malloc(100 * sizeof(int));
    *returnSize = 0;
    preorderHelper(root, result, returnSize);
    return result;
}
 
