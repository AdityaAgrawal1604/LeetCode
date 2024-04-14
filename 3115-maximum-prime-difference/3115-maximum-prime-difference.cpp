class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int l = INT_MAX;
        int h = INT_MIN;
        for(int i = 0;i<n;i++){
            int x = nums[i];
            int f = 0;
            for(int j = 2;(j*j)<=x;j++){
                if((x%j)==0){
                    f = 1;
                    break;
                }
            }
            if(!f&&(x!=1)){
                l = min(l,i);
                h = max(h,i);
            }
        }
        // cout<<l<<" "<<h<<endl;
        return (h-l);
    }
};