class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> vp;
        for(auto x:mp){
            vp.push_back({x.second,x.first});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        vector<int> ans;
        for(int i = 0;i<k;i++){
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};