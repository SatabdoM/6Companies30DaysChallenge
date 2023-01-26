#include<bits/stdc++.h>
using namespace std;

map<pair<int,vector<int>>,int> mp;
    int f(int index,vector<vector<int>>&special,vector<int>& price,vector<int>& needs)
    {
        //base case
        if(index==special.size())
        {
            //we have exhaused the list of specials
            int seperate_prices=0;
            for(int i=0;i<needs.size();i++)
            {
                if(needs[i]>0)//we have additional items which needs to be purchased seperately
                    seperate_prices+=(needs[i]*price[i]);
            }
            return seperate_prices;
        }
        if(mp.count({index,needs})) return mp[{index,needs}];
        //taking the special at index:
        //checking if it ch=an be taken:
        int fl=0;
        int take=INT_MAX;
        int size=special[0].size();
        int price_amt=special[index][size-1];
        vector<int>temp_needs=needs;
        for(int i=0;i<size-1;i++)
        {
            int special_qty=special[index][i];
            if(temp_needs[i]>=special_qty)
            {
                temp_needs[i]-=special_qty;
            }
            else
            {
                fl=1;
                break;
            }
        }
        if(fl==0)//the special at the index be taken
            take=price_amt+f(index,special,price,temp_needs);

        int not_take=0+f(index+1,special,price,needs);

        return mp[{index,needs}]=min(take,not_take);

    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        
        return  f(0,special,price,needs);
    }
