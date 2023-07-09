class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans1 = 1e9;
        int ans2 = -1e9;
        for(int i = 0;i<n;i++){
            int k = nums[i];
            k = t-k;
            int l = i+1;
            int h = n-1;
            while(l<h){
                int to = nums[l]+nums[h];
                if(to<k){
                    ans2 = max(ans2,to+nums[i]);
                    l++;
                }else{
                    ans1 = min(ans1,to+nums[i]);
                    h--;
                }
            }
        }
        if(abs(ans1-t)<abs(ans2-t)){
            return ans1;
        }
        return ans2;
    }
};