#include<bits/stdc++.h>
using namespace std;

    int evalRPN(vector<string>& tokens) 
    {
        stack<string>st;
        for(auto it:tokens)
        {
            if(it=="+" || it=="-" || it=="*" || it=="/")
            {
                int sec=stoi(st.top());
                st.pop();
                int first=stoi(st.top());
                st.pop();
                int ans=0;
                if(it=="+")ans=first+sec;
                else if(it=="-")ans=first-sec;
                else if(it=="*")ans=first*sec;
                else if(it=="/")ans=first/sec;
                st.push(to_string(ans));
            }
            else
            {
                st.push(it);
            }
        }
        int f_ans=stoi(st.top());
        return f_ans;

        
    }