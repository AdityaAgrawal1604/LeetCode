class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        sort(s1.begin(),s1.end());
        for(int i = 0;i<m-n+1;i++){
            string k = s2.substr(i,n);
            sort(k.begin(),k.end());
            if(s1==k){
                return true;
            }
        }
        return false;
    }
};