vector<int>ans;
    void helper(TreeNode* root){
        if(root==NULL)return;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       helper(root);
       return ans;
    }
