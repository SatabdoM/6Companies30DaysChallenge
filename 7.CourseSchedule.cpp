#include<bits/stdc++.h>
using namespace std;

void bfs(queue<int>q,vector<int>&id,vector<int>&order,vector<vector<int>>&adj)
{
    while(!q.empty())
    {
        int node=q.front();
        order.push_back(node);
        q.pop();
        for(auto it:adj[node])
        {
            id[it]--;
            if(id[it]==0)
                q.push(it);
        }
        
    }
    
}
bool canFinish(int n, vector<vector<int>>& req) 
{
    //in-degree array to store the in degrees of the nodes
    vector<int>id(n,0);
    vector<int>order;
    vector<vector<int>>adj(n);
    for(auto it:req)
    {
        id[it[0]]++;
        adj[it[1]].push_back(it[0]);
    }
    //queue ds to store the nodes with 0 in degrees
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(id[i]==0)
            q.push(i);
    }
    bfs(q,id,order,adj);
    if(order.size()==n)return true;
    return false; 
}