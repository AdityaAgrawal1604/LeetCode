//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int findMaxSum(int *arr, int n) {
	   int pprev = 0;
	   int prev = arr[0];
	   for(int i = 2;i<=n;i++){
	       int take = arr[i-1]+pprev;
	       int notTake = prev;
	       int curr = max(take,notTake);
	       pprev = prev;
	       prev = curr;
	   }
	   return prev;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends