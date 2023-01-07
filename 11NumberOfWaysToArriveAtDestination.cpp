#include<bits/stdc++.h>
using namespace std;


int countPaths(int n, vector<vector<int>>& roads) 
{
    int mod=(1e9+7);
    //making the adjacency list
    vector<vector<pair<int,int>>>adj(n);
    for(auto it:roads)
    {
        int start=it[0];
        int end=it[1];
        int d=it[2];
        adj[start].push_back({end,d});
        adj[end].push_back({start,d});
    }
    //distance array to store the min diantance to reach the node
    vector<long long >dist(n,1e18);
    dist[0]=0;
    //ways array to store the no of ways to reach the node in the min distance
    vector<long long >ways(n,0);
    ways[0]=1;
    //priority queue: distance,node
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;        
    pq.push({0,0});
    while(!pq.empty())
    {
        long long cdist=pq.top().first;
        long long node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            long long enode=it.first;
            long long edist=it.second;
            long long tdist=cdist+edist;
            //case 1:this is the first time im coming with this distance
            if(tdist<dist[enode])
            {
                dist[enode]=tdist;//update the distance array
                ways[enode]=ways[node];
                pq.push({tdist,enode});
            }
            //case 2:
            else if(tdist==dist[enode])
            {
                ways[enode]=(ways[enode]+ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;    
}