 vector<int>ans;
    void help(TreeNode* root){
        if(root==NULL)return;
        help(root->left);
        help(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        help(root);
        return ans;
    }
