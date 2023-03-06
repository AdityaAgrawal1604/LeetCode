class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        int j = 0;
        int y = 0;
        int n = arr.size();
        while(y!=k&&j<n){
            if(i==arr[j]){
                j++;
                i++;
            }else{
                i++;
                y++;
            }
        }
        if(j==n){
            i+=(k-y);
        }
        return i-1;
    }
};