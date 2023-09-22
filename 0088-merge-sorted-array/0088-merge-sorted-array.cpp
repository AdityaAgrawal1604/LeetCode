class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)     {
            // nums1=nums1+nums2;
        
        for(int i = m;i<n+m;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
//         if(n==0){
//             return;
//         }
//         if(m==0){
//             nums1 = nums2;
//             return;
//         }
//         int i = 0;
//         for(int j = m;j<n+m;j++){
//             nums1[j] = nums2[i];
//             i++;
//         }
//         i = 0;
//         int j = m;
//         int f = 0;
//         while(i<(n+m)){
//             if(i>j){
//                 f = 1;
//             }
//             if(((!f)&&nums1[i]>nums1[j])||(f&&(nums1[j]>nums1[i])))             {
//                 swap(nums1[i],nums1[j]);
//             }

//             if(f){
//                 i++;
//                 j++;
//             }else{
//                 i++;
//             }
            
//         }
    }
};