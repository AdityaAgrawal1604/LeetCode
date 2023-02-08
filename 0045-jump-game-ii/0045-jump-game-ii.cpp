class Solution {
public:
    int f(int i,vector<int> &nums,vector<int> &dp){
        if(i==(nums.size()-1)){
            return 0;
        }
        if(i>=(nums.size())){
            return 1e9;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = 1e9;
        for(int j = 1;j<=nums[i];j++){
            take = min(take,f(i+j,nums,dp));
        }
        return dp[i] = (1+take);
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};