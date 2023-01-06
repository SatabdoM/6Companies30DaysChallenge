#include<bits/stdc++.h>
using namespace std;

void f(int k,int sum,int start,vector<int>&temp,vector<vector<int>>&ans)
{
    //base case
    if(k==0)
    {
        cout<<sum;
        if(sum==0)
        {
            ans.push_back(temp);
        }
        return;
    }
    for(int i=start;i<=9;i++)
    {
        if(sum>=i)
        {
            temp.push_back(i);
            f(k-1,sum-i,i+1,temp,ans);
            temp.pop_back();
        }  
    }
}
vector<vector<int>> combinationSum3(int k, int sum)
{
    vector<vector<int>>ans;
    vector<int>temp;
    f(k,sum,1,temp,ans);
    return ans;
}
