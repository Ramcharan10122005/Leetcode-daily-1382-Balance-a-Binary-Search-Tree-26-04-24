/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int size(struct TreeNode* x) {
    if (x == NULL) {
        return 0;
    }
    return size(x->left) + size(x->right) + 1;
}
void inorder(struct TreeNode* x, int* index, int* arr) {
    if (x != NULL) {
        inorder(x->left, index, arr);
        arr[(*index)++] = x->val;
        ;
        inorder(x->right, index, arr);
    }
}
struct TreeNode* build(int* nums, int beg, int end) {
    if (end < beg)
        return NULL;
    int mid = (beg + end) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = build(nums, beg, mid - 1);
    root->right = build(nums, mid + 1, end);
    return root;
}
struct TreeNode* balanceBST(struct TreeNode* root) {
    int count = size(root);
    int* arr = malloc(count * sizeof(int));
    int index = 0;
    inorder(root, &index, arr);
    if (count <= 0)
        return NULL;
    else
        return build(arr, 0, count - 1);
}
