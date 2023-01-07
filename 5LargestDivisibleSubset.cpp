#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>&arr) 
{
    int n=arr.size();
    int lis_ind=0;
    int lis_len=0;
    vector<int>ans;

    sort(arr.begin(),arr.end());

    vector<int>dp(n,1);//store the length
    vector<int>hash(n,0);//stores the last index of the subsequence

    for(int i=0;i<n;i++)
    {
        hash[i]=i;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]%arr[j]==0)
            {
                if(dp[j]+1 > dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                    if(dp[i]>lis_len)
                    {
                        lis_len=dp[i];
                        lis_ind=i;
                    }
    }}}}
    
    //Backtracking the hash array and finding the elements
    int ind=lis_ind;
    while(hash[ind]!=ind)
    {
        ans.push_back(arr[ind]);
        ind=hash[ind];
    }
    ans.push_back(arr[ind]);
    reverse(ans.begin(),ans.end());
return ans;
}