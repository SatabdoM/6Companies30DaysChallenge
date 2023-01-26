class Solution {
public:
    int find(int n,int k)
    {
        if(n==1)
            return 0;
        return (find(n-1,k)+k)%n;

    }

    int findTheWinner(int n, int k) 
    {
        return find(n,k)+1;
    }
};
