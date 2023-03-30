

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& ed, int k) {
        vector<vector<int>> gp(vals.size());
            for(auto x : ed)
            {
               gp[x[0]].push_back(vals[x[1]]);
               gp[x[1]].push_back(vals[x[0]]);
            }
        int ans = -1e9;
        for(int i = 0; i < vals.size(); ++i)
        {
            sort(gp[i].rbegin(), gp[i].rend());
            int temp = k;
            int add = vals[i];
            if(gp[i].size())
            {
                for(int j = 0; j < gp[i].size() && temp; ++j)
                {
                    if(gp[i][j] < 0) continue;
                    add += gp[i][j];
                    temp--;
                    // add = 1;
                }
            }
            ans = max(ans,add);
        }
        return ans;
        
    }
};