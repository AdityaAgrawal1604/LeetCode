//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int mini = 0;
        map<int,int> mp;
        int sm = 0;
        // mp[0] = 0;
        for(int i = 0;i<n;i++){
            sm+=A[i];
            if(mp[sm]){
                if(sm==0){
                    mini = i+1;
                    continue;
                }
                mini = max(mini,(i-mp[sm]+1));
            }else{
                if((sm==0)){
                    mini = i+1;
                    continue;
                }
                mp[sm] = i+1;
            }
            // cout<<mini<<" "<<sm<<" "<<mp[sm]<<endl;
            
        }
        if(sm==0){
            return n;
        }
        return mini;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends