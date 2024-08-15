class DSU{
    public:
    vector<int>comp_size;
    vector<int>parent;
    DSU(int n)
    {
        comp_size.resize(n,1);
        parent.resize(n);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
    }
    int find(int a)
    {
        if(a==parent[a]){
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    void Union(int a,int b)
    {
        a = find(a);
        b = find(b);
        if(a!=b)
        {
            if(comp_size[a]>=comp_size[b])
            {
                comp_size[a]+=comp_size[b];
                parent[b] = a;
            }
            else
            {
                comp_size[b]+=comp_size[a];
                parent[a] = b;
            }
        }
    }
    void reset(int a)
    {
        parent[a] = a;
        comp_size[a] = 1;
    }
};

class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(int i = 0;i<meetings.size();i++)
        {
            if(meetings[i][0]>meetings[i][1])
            {
                int temp = meetings[i][0];
                meetings[i][0] = meetings[i][1];
                meetings[i][1] = temp;
            }
        }
        sort(meetings.begin(),meetings.end(),cmp);
        DSU d(n);
        d.Union(0,firstPerson);
        int i = 0;
        int x = meetings.size();
        while(i<x)
        {
            int time = meetings[i][2];
            vector<int>v;
            while(i<x && meetings[i][2]==time)
            {
                v.push_back(meetings[i][0]);
                v.push_back(meetings[i][1]);
                d.Union(meetings[i][0],meetings[i][1]);
                i++;
            }
            for(auto it:v)
            {
                if(d.find(it)!=d.find(0))
                {
                    d.reset(it);
                }
            }
        }
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            cout<<d.find(i)<<" ";
            if(d.find(i)==d.find(0))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
