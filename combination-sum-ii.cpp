class Solution {
public:
    void solve(int i,vector<int>& candidates, int target,set<vector<int>>&ans,vector<int>&out)
    {
        if(target==0)
        {
            ans.insert(out);
            return;
        }
        if(target<0)
        return;

        
       
        int prev = -1;

        for(int j=i;j<candidates.size();j++)
        {
            if(candidates[j]==prev)
            continue;

            out.push_back(candidates[j]);
            solve(j+1,candidates,target-candidates[j],ans,out);
            out.pop_back();

            prev = candidates[j];
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>>ans;
        vector<int>out;
        solve(0,candidates,target,ans,out);
        vector<vector<int>>ans2;
        for(auto it:ans)
        {
            ans2.push_back(it);
        }
        return ans2;
    }
};