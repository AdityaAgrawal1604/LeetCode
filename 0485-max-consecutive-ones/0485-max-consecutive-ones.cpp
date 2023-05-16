class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==1){
                int l = i;
                while(i<n&&nums[i]==1){
                    i++;
                }
                maxi = max(maxi,(i-l));
                i--;
            }
        }
        return maxi;
    }
};