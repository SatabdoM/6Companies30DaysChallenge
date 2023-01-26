class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) 
    {
        //creating the adj matrix
        vector<vector<int>>adjm(n,vector<int>(n,INT_MAX));
        for(auto edge:edges)
        {
            int node1=edge[0];
            int node2=edge[1];
            int dist=edge[2];
            adjm[node1][node2]=dist;
            adjm[node2][node1]=dist;
        }
        int city=-1;
        int max_count=n;
        //Applying Floyd Warshall's algorithm to find the shortest path between nodes
        for(int via=0;via<n;via++)
        {
            for(int r=0;r<n;r++)
            {
                int count=-1;
                for(int c=0;c<n;c++)
                {
                    if(r==c)
                    {
                        adjm[r][c]=0;
                        continue;
                    }
                    if(r==via || c==via)
                        continue;
                    if(adjm[r][via]==INT_MAX || adjm[via][c]==INT_MAX)
                        continue;
                    adjm[r][c]=min(adjm[r][c] ,adjm[r][via]+adjm[via][c]);
                    if(adjm[r][c]<=thresh)
                    {
                        if(count==-1)
                            count=0;
                        count++;
                    }
                        
                }
                if(count==-1)continue;
                else if(count<=max_count)
                {
                    cout<<count<<endl;
                    city=r;
                    max_count=count;
                }
            }
        }
        return city;        
    }
};
