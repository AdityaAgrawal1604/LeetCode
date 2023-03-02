class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i = 0;
        int j = 0;
        int n = s.length();
        int maxi = 0;
        while(i<n&&j<n){
            if(mp[s[j]]){
                mp[s[i]]--;
                i++;
            }else{
                mp[s[j]]++;
                j++;
                maxi = max(maxi,j-i);
            }
        }
        return maxi;
    }
};