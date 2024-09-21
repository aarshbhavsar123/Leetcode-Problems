class Node{
    public:
    vector<Node*>links;
    int count;
    Node()
    {
        links.resize(2,NULL);
        count = 0;
    }
};
class trie{
    public:
    Node* root;
    trie()
    {
        root = new Node();
    }
    void insert(int x)
    {
        Node* node = root;
        for(int i = 19;i>=0;i--)
        {
            int bit = (x>>i)&1;
            if(node->links[bit]==NULL)
            {
                node->links[bit] = new Node();
            }
            node = node->links[bit];
            node->count++;
        }
    }
        int getMax(int x)
        {
            Node* node = root;
            int maxi = 0;
            for(int i = 19;i>=0;i--)
            {
                int bit = (x>>i)&1;
                if(node->links[1-bit]!=NULL)
                {
                    maxi|=(1<<i);
                    node = node->links[1-bit];
                }
                else
                {
                    node = node->links[bit];
                }
            }
            return maxi;
        }
        void remove(int x)
        {
            Node* node = root;
            for(int i = 19; i >= 0; i--)
            {
                int bit = (x >> i) & 1;
                if (node->links[bit] != NULL) 
                {
                    node->links[bit]->count--;
                    if (node->links[bit]->count == 0) 
                    {
                        delete node->links[bit];
                        node->links[bit] = NULL;
                        return;  
                    }
                }
                node = node->links[bit];
            }
        }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = 0;
        trie* t = new trie();
        int maxi = 0;
        while(r<n)
        {
            t->insert(nums[r]);
            while(nums[r]>2*nums[l])
            {
                t->remove(nums[l]);
                l++;
            }
            maxi = max(maxi,t->getMax(nums[r]));
            r++;
        }
        return maxi;
    }
};