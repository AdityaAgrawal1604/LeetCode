class Solution {
public:
    int minOperations(vector<int>& nums) {
      int ans = 0;
       int mx = -1;
        sort(nums.begin(), nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        map<int,int> mp;
        while(j<n)
        {
            mp[nums[j]]++;
            int sm = (mp.begin()->first);
            int lg = (mp.rbegin()->first);
            while(lg-sm > n-1)
            {
                if(mp[nums[i]] == 1) mp.erase(nums[i]);
                else mp[nums[i]]--;
                i++;
                sm = (mp.begin()->first);
                lg = (mp.rbegin()->first);
            }
            mx = max(mx, (int)mp.size());
            j++;
        }
        return n-mx;
    }
};