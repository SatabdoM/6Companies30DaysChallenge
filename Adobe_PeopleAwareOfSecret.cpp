class Solution {
public:
    int mod=1e9+7;
    int f(int day,int delay,int forget,int max_day,vector<int>&dp)
    {
        //base case
        if(day>max_day)
            return 0;

        if(dp[day]!=-1)
            return dp[day];

        //let us define the variables
        int start=day+delay;
        int forget_day=day+forget;
        int count=0;

        for(int i=start;i<=min(forget_day-1,max_day);i++)
        {
            count=(count+ f(i,delay,forget,max_day,dp)%mod  )%mod;
        }

        if(forget_day>max_day)
            return dp[day]=count+1;
        else return dp[day]=count;

    }
    int peopleAwareOfSecret(int max_day, int delay, int forget) 
    {
        vector<int>dp(max_day+1,-1);
        int ans=f(1,delay,forget,max_day,dp);
        return ans;
    }
};
