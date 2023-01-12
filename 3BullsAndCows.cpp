#include<bits/stdc++.h>
using namespace std;

    string getHint(string secret, string guess) 
    {
        int cows=0,bulls=0;
        vector<int>s(10),g(10);
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
            else
            {
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            
            }
        }
        //checking the number of cows
        for(int i=0;i<10;i++)
        {
            cows+=min(s[i],g[i]);
        }
        string ans;
        string b=to_string(bulls);
        ans+=b;
        ans+='A';
        string c=to_string(cows);
        ans+=c;
        ans+='B';
        return ans;
        
    }
