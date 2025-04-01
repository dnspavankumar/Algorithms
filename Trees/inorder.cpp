 vector<int>ans;
    void help(TreeNode* root){
        if(root==NULL)return;
        help(root->left);
        ans.push_back(root->val);
        help(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        help(root);
        return ans;
    }
