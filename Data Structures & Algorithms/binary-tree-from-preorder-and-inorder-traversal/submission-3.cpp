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
    int preInd;
    int inInd;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit, int n) {
        if(preInd==n) return nullptr;
        if(inorder[inInd]==limit) {
            inInd++;
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[preInd++]);
        root->left=dfs(preorder, inorder, root->val, n);
        root->right=dfs(preorder, inorder, limit, n);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preInd=0;
        inInd=0;
        int n=preorder.size();
        return dfs(preorder, inorder, INT_MAX, n);


        // int i=0, j=0;
        // int n=preorder.size();
        // TreeNode* dummy=new TreeNode(0);
        // TreeNode* curr=dummy;

        // while(i<n && j<n) {
        //     curr->right=new TreeNode(preorder[i], nullptr, curr->right);
        //     curr=curr->right;
        //     i++;

        //     while(i<n && curr->val!=inorder[j]) {
        //         curr->left=new TreeNode(preorder[i], nullptr, curr);
        //         curr=curr->left;
        //         i++;
        //     }

        //     j++;

        //     while(curr->right && j<n && curr->right->val==inorder[j]) {
        //         TreeNode* prev=curr->right;
        //         curr->right=nullptr;
        //         curr=prev;
        //         j++;
        //     }
        // }

        // return dummy->right;
    }
};
