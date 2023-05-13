//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int i,int j,int wt[],int val[],vector<vector<int>>&dp){
        if(i<0){
            // return 0;
            // if(j>=wt[i]){
            //     return val[i];
            // }
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take = 0;
        if(j>=wt[i]){
            take = val[i]+f(i-1,j-wt[i],wt,val,dp);
        }
        int notTake = f(i-1,j,wt,val,dp);
        return dp[i][j] = max(take,notTake);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(w+1,-1));
       return f(n-1,w,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends