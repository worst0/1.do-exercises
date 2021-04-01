/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode *> s;
        TreeNode *p = root, *pre = nullptr;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            if (s.empty()) continue;
            p = s.top();
            s.pop();
            if (!p->right || p->right == pre) {
                ans.push_back(p->val);
                pre = p;
                p = nullptr;
            } else {
                s.push(p);
                p = p->right;
            }
        }
        return ans;
    }
};
// @lc code=end

