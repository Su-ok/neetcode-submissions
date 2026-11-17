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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0, j=0;
        int n=preorder.size();
        TreeNode* dummy=new TreeNode(0);
        TreeNode* curr=dummy;

        while(i<n && j<n) {
            curr->right=new TreeNode(preorder[i], nullptr, curr->right);
            curr=curr->right;
            i++;

            while(i<n && curr->val!=inorder[j]) {
                curr->left=new TreeNode(preorder[i], nullptr, curr);
                curr=curr->left;
                i++;
            }

            j++;

            while(curr->right && j<n && curr->right->val==inorder[j]) {
                TreeNode* prev=curr->right;
                curr->right=nullptr;
                curr=prev;
                j++;
            }
        }

        return dummy->right;
    }
};
