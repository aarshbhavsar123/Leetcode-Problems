class Solution {
public:
    long long maximumTotalSum(vector<int>& arr) {
        long long n = arr.size();
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        long long sum = arr[0];
        for(long long i = 1;i<n;i++)
        {
            if(arr[i]>=arr[i-1])
            {
                arr[i]=arr[i-1]-1;
                if(arr[i]<=0)
                return -1;
            }
            sum+=arr[i];
        }
        return sum;
    }
};