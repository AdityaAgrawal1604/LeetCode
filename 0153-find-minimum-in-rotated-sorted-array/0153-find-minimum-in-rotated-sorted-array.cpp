class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int i = 0;
        while(i<n&&nums[i]==nums[0]) i++;
        // if(i==n){
        //     if(t==nums[0]) return true;
        //     return false;
        // }
        int l = i;
        int h = n-1;
        int mid = (l+h)/2;
        int pivot = n;
        while(l<=h){
            if(nums[mid]>nums[0]) l = mid+1;
            else{
                pivot = min(mid,pivot);
                h = mid-1;
            }
            mid = (l+h)/2;
        }
        return nums[pivot%n];
        // cout<<pivot<<endl;
        // l = 0;
        // h = pivot-1;
        // mid = (l+h)/2;
        // while(l<=h){
        //     if(nums[mid]==t) return true;
        //     else if(nums[mid]>t){
        //         h = mid-1;
        //     }else{
        //         l = mid+1;
        //     }
        //     mid = (l+h)/2;
        // }
        // l = pivot;
        // h = n-1;
        // mid = (l+h)/2;
        // while(l<=h){
        //     if(nums[mid]==t) return true;
        //     else if(nums[mid]<t) l = mid+1;
        //     else h = mid-1;
        //     mid = (l+h)/2;
        // }
        // return false;
    }
};