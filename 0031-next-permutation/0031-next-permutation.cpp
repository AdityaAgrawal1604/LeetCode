#include<bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                int ind = -1;
                int k = INT_MAX;
                for(int j = i+1;j<n;j++){
                    if(k>nums[j]&&nums[j]>nums[i]){
                        k = nums[j];
                        ind = j;
                    }
                    cout<<k<<" "<<nums[j]<<" "<<ind<<endl;
                }
                
                swap(nums[i],nums[ind]);
                sort(nums.begin()+i+1,nums.end());
                break;
            }
            if(i==0){
                reverse(nums.begin(),nums.end());
            }
        }
    }
};