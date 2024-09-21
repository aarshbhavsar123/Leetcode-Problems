class Node{
    public:
    vector<Node*>links;
    Node()
    {
        links.resize(2,NULL);
    }
};
class Trie{
    public:
    Node* root;
    set<int>st;
    Trie()
    {
        this->root = new Node();
    }
    bool isValid(int x, int y) 
    {
        return abs(x - y) <= min(x, y);
    }

    void f(set<int>& src, set<int>& res, int x) 
    {
    
        int lowerBound = x - min(x, *src.begin());
        int upperBound = x + min(x, *src.rbegin());
        auto itLow = src.lower_bound(lowerBound);
        auto itHigh = src.upper_bound(upperBound);
        for (auto it = itLow; it != itHigh; ++it) {
            if (isValid(x, *it)) {
                res.insert(*it);
            }
        }
    }
    void insert(int x)
    {
        st.insert(x);
        Node* node = root;
        int num = 0;
        for(int i = 31;i>=0;i--)
        {
            int bit = (x>>i)&1;
            if(node->links[bit]==NULL)
            {
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }
    }
    int getMax(int x)
    {
        set<int>st2;
        f(st,st2,x);
        int maxi = 0;
        for(auto it:st2)
        {
            maxi = max(maxi,x^it);
        }
        return maxi;
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                if(abs(nums[j]-nums[i])<=min(nums[j],nums[i]))
                {
                    maxi = max(maxi,nums[i]^nums[j]);
                }
            }
        }
        return maxi;
    }
};