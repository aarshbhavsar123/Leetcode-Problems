class Solution {
public:
    int countPrimes(int n) {
        
        vector<int>visited(n+1,false);
        int count = 0;

        for(int i=2;i<=n;i++)
        {
            if(visited[i])
            continue;

            else
            {
                int j = i;
                int k = 2;
                while(j<n)
                {
                    j=i*k;
                    k++;
                    if(j < n) 
                        visited[j] = true;
                }
            }
        }
        if(n==0)
        return 0;
        if(n==1)
        return 0;
        for(auto it:visited)
        {
            if(!it)
            {
                count++;
            }
        }
        return count-3;
    }
};