class Solution {
public:
        int kthElement(vector<int>arr1, vector<int> arr2, int n, int m, int k)
    {
        // cout<<arr2[10]<<endl;
        int l= 1;
        int h = k;
        int mid = (l+h)/2;
        int g = -1;
        while(l<=h){
            
            if(n<mid){
                h = mid-1;
            }else if(m<(k-mid)){
                l = mid+1;
            }else{
                // cout<<k-mid<<" "<<mid<<" "<<arr2[k-mid-1]<<" "<<arr1[mid-1]<<endl;
                if((k-mid-1)>=0&&arr2[k-mid-1]>arr1[mid-1]){
                    // cout<<1<<endl;
                    
                    l = mid+1;
                }else if((k-mid)==m){
                    // cout<<2<<endl;
                    g = mid;
                    break;
                }else if(arr2[k-mid]<arr1[mid-1]){
                    // cout<<3<<endl;
                    h = mid-1;
                }else{
                    // cout<<4<<endl;
                    g = mid;
                    // cout<<g<<endl;
                    break;
                }
            }
            mid = (l+h)/2;
        }
        // cout<<g<<endl;
        if(g!=-1){
            return arr1[g-1];
        }
        // cout<<g<<endl;
        l = 1;
        h = k;
        mid = (l+h)/2;
        while(l<=h){
            // cout<<mid<<endl;
            // cout<<k-mid<<" "<<mid<<" "<<arr1[k-mid-1]<<" "<<arr2[mid-1]<<endl;
            if(m<mid){
                h = mid-1;
            }
            else if(n<(k-mid)){
                l = mid+1;
            }else{
                if((k-mid-1)>=0&&arr1[k-mid-1]>arr2[mid-1]){
                    l = mid+1;
                }else if((k-mid)==n){
                    g = mid;
                    break;
                }else if(arr1[k-mid]<arr2[mid-1]){
                    h = mid-1;
                }else{
                    g = mid;
                    break;
                }
            }
            mid = (l+h)/2;
        }   
        // cout<<g<<endl;
        return arr2[g-1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int  n = nums1.size();
        int  m = nums2.size();
        double ans;
        if((n+m)&1){
            ans = kthElement(nums1,nums2,n,m,(n+m+1)/2)*1.0;
        }else{
            ans = kthElement(nums1,nums2,n,m,(n+m)/2)*1.0;
            ans += kthElement(nums1,nums2,n,m,(n+m+2)/2);
            ans/=2;
        }
        return ans;
    }
};