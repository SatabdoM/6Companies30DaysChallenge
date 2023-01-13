#include<bits/stdc++.h>
using namespace std;
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        stack<TreeNode*>st1,st2;
        TreeNode *t1=root1,*t2=root2;
        vector<int>ans;
        while(t1 || t2 || !st1.empty() || !st2.empty())
        {
            while(t1)
            {
                st1.push(t1);
                t1=t1->left;
            }
            while(t2)
            {
                st2.push(t2);
                t2=t2->left;
            }
            //both t2 and t1 is NULL
            if(st2.empty() || (!st1.empty() && !st2.empty() && st2.top()->val >= st1.top()->val))
            {
                t1=st1.top();
                st1.pop();
                ans.push_back(t1->val);
                t1=t1->right;
            }
            else if(st1.empty() || (!st1.empty() && !st2.empty() && st1.top()->val >= st2.top()->val))
            {
                t2=st2.top();
                st2.pop();
                ans.push_back(t2->val);
                t2=t2->right;
            }
            
        }
        return ans;
        
    }
};
