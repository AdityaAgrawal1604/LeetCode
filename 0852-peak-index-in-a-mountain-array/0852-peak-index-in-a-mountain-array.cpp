class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 1;
        int r = n-2;
        int mid = (l+r)/2;
        while(l<=r){
            if((arr[mid]>arr[mid+1])&&(arr[mid]>arr[mid-1])){
                return mid;
            }else if((arr[mid]>arr[mid+1])&&(arr[mid]<arr[mid-1])){
                r = mid-1;
            }else{
                l = mid+1;
            }
            mid = (l+r)/2;
        }
        return mid;
    }
};