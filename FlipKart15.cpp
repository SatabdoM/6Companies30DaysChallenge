class Solution {
public:
    map<TreeNode*,int>mp;
    int rob(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        if(mp[root])
            return mp[root];
        //1.We can take the value of the node and jump to the child->child
        //2.We can not take this node and jump to the child
        int take=root->val;
        int not_take=0;
        if(root->left!=NULL)
            take+=rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL)
            take+=rob(root->right->left)+rob(root->right->right);
        
        not_take+=rob(root->left)+rob(root->right);
        return mp[root]= max(take,not_take); 
    }
};
