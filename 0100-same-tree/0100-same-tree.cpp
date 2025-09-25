/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if (p == nullptr && q == nullptr) {
            return true;
        }

        // Case where one is empty and the other is not, they are not the same.
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Recursive step:
        // 1. Check if the current nodes have the same value.
        // 2. Recursively check if the left subtrees are the same.
        // 3. Recursively check if the right subtrees are the same.
        if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return true;
        }

        return false;
    }
};