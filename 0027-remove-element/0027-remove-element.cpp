class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k;
        for(int i = 0;i<n;i++){
            if(nums[i]==val){
                int f = 0;
                for(int i1 = i;i1<n;i1++){
                    if(nums[i1]!=val) f = 1;
                }
                if(!f) return i;
                for(int j = i+1;j<n;j++){
                    swap(nums[j],nums[j-1]);
                }
                // for(int f = 0;f<n;f++) cout<<nums[f]<<" ";
                if(nums[i]==val) i--;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i]==val){
                k = i;
                break;
            }
        }
        return k;
    }
};