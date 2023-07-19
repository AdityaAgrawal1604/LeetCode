class Solution {
public:
    void merge(int l,int mid,int r,vector<int> &nums){
        vector<int> left,right;
        for(int i = l;i<=mid;i++){
            left.push_back(nums[i]);
        }
        for(int i = mid+1;i<=r;i++){
            right.push_back(nums[i]);
        }
        int k = l;
        int i=0,j=0;
        while(i<left.size()&&j<right.size()){
            if(left[i]<right[j]){
                nums[k]=left[i];
                i++;
            }else{
                nums[k]=right[j];
                j++;
            }
            k++;
        }
        while(i<left.size()){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<right.size()){
            nums[k]=right[j];
            j++;
            k++;
        }
    }
    void mergeSort(int l,int r,vector<int> &nums){
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};