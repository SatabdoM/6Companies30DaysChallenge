#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
    vector<int> mergeVectors(vector<int>& v1, vector<int>& v2) {
        vector<int> res;
        int i = 0, j = 0;
        
        while (i < v1.size() || j < v2.size()) {
            if (i == v1.size()) res.push_back(v2[j++]);
            else if (j == v2.size()) res.push_back(v1[i++]);
            else res.push_back(v1[i] < v2[j] ? v1[i++] : v2[j++]);
        }
        
        return res;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        inorder(root1, res1);
        inorder(root2, res2);
        return mergeVectors(res1, res2);
    }
};