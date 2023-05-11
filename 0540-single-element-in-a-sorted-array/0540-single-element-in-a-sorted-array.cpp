class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int l = 0;
        int h = n-1;
        int mid = (l+h)/2;
        while(l<=h){
            if(mid&1){
                if(nums[mid-1]==nums[mid]){
                    l = mid+1;
                }else{
                    h = mid-1;
                }
            }else{
                if(mid!=0){
                    if(nums[mid-1]==nums[mid]){
                        h = mid-1;
                    }else{
                        l = mid+1;
                    }
                }else{
                    if(nums[mid+1]==nums[mid]){
                        l = mid+1;
                    }else{
                        break;
                    }
                }
            }
            mid = (l+h)/2;
        }
        return nums[mid];
    }
};