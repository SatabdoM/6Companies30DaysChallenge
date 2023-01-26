#include<bits/stdc++.h>
using namespace std;
    bool f(int i,int bucketNum,int bucketSum,int reqSum,int k,vector<int>&nums,vector<int>& alreadyPicked)
    {
        //base case
        if(bucketNum==k+1)
            return true;
        if(bucketSum==reqSum)
            return f(0,bucketNum+1,0,reqSum,k,nums,alreadyPicked);
        if(bucketSum>reqSum)
            return false;
        if(i>=nums.size())return false;

        if(alreadyPicked[i]==1)
            return f(i+1,bucketNum,bucketSum,reqSum,k,nums,alreadyPicked);
        else
        {
            //pick
            bucketSum+=nums[i];
            alreadyPicked[i]=1;
            bool pick=f(i+1,bucketNum,bucketSum,reqSum,k,nums,alreadyPicked);
            //undo the changes
            bucketSum-=nums[i];
            alreadyPicked[i]=0;

            //not pick
            bool not_pick=f(i+1,bucketNum,bucketSum,reqSum,k,nums,alreadyPicked);
            return pick|not_pick;
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        int total_sum=0;
        for(int it:nums)
            total_sum+=it;
        if(total_sum%k!=0)
            return false;
        int reqSum=total_sum/k;
        vector<int>alreadyPicked(nums.size(),false);
        return f(0,1,0,reqSum,k,nums,alreadyPicked);
    }
