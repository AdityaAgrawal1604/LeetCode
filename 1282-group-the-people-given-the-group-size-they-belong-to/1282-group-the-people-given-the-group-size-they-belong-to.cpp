class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> mp;
        int n = g.size();
        for(int i = 0;i<n;i++) mp[g[i]].push_back(i);
        vector<vector<int>> ans;
        for(auto x:mp){
            vector<int> a;
            int cnt = x.first;
            for(int i = 0;i<x.second.size();i++){
                if(!cnt){
                    cnt = x.first;
                    ans.push_back(a);
                    a.clear();
                }
                a.push_back(x.second[i]);
                cnt--;
            }
            ans.push_back(a);
        }
        return ans;
    }
};