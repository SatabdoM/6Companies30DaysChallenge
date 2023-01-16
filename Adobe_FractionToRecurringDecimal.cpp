#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int n, int d)
    {
        string ans;
        if((n<0 && d>0) || (n>0 && d<0))
            ans+='-';
        n=abs(n);
        d=abs(d);
        long long q=n/d;//initial quotient
        long long rem=n%d;//initial remainder
        ans+=to_string(q);
        if(rem==0) return ans;//there is no decimal part
        ans+='.';
        int fl=0;//flag variable to determine if theb decimal is recurring
        int ind_start=-1;//starting index of the recurring part of the decimal
        int index=0;//to store the index of all the numbers after point
        unordered_map<int,unordered_map<int,int>>mp;//quotient-->remainder-->index of number
        string after_pt;//string to store all the numbers after point
        while(rem!=0)
        {
            rem*=10;
            long long q2=rem/d;
            rem=rem%d;
            if(mp[q2][rem])//means the quotient-->remainder already exists thus the decimal part is recurring
            {
                fl=1;
                ind_start=mp[q2][rem];//the index of the start of the recuuring part of the decimal
                break;
            }
            else
            {
                after_pt+=to_string(q2);
                mp[q2][rem]=index++;
            }
        }
        if(fl==0)//contains no recurring number just concatenate the strings
            ans+=after_pt;
        else
        {
            //contains a recurring part
            for(int i=0;i<after_pt.length();i++)
            {
                if(i==ind_start)//this is the start of the recurring part of the decimal nos
                    ans+='(';
                ans+=after_pt[i];
            }
            ans+=')';
        }
        return ans;
    }
};
