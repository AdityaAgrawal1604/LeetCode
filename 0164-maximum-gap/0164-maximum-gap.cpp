class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = 0;
        if(n<2) return 0;
        for(int i = 1;i<n;i++){
            mini = max(mini,(nums[i]-nums[i-1]));
        }
        return mini;
    }
};