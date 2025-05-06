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

    // void solve(TreeNode* root, int target, int sum, vector<int> path, vector<vector<int>> &ans) {//path ko by reference nhi liya hai
    void solve(TreeNode* root, int target, int sum, vector<int> &path, vector<vector<int>> &ans) {//path ko by reference liya hai
        if(root == NULL) {
            return ;
        }

        // root pkka non-null hai,
        sum = sum + root->val;
        path.push_back(root->val);

        // check for leaf node
        if(root->left == NULL && root->right == NULL) {
            if(sum == target) {
                ans.push_back(path);
                path.pop_back();//with by reference 
                return;
            }
            else{
                path.pop_back();
                return;
            }
        }

        solve(root->left, target, sum, path, ans);
        solve(root->right, target, sum ,path, ans);

        //backtrack
        path.pop_back();//with by reference

        //jab humm path ko by refrence nhi karte hai toh hamme backtracking vaali chij karne ki jarrorat nhi padti hai
    } 

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum= 0 ;
        vector<int> path;
        vector<vector<int>>ans;

        solve(root,targetSum , sum,path,ans);
        return ans;
    }
};

//imp-> https://chatgpt.com/share/6819c9c6-3060-8007-a9a0-e80af5b74b5f 