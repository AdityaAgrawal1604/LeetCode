class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int i = 0;
        int j = n-1;
        while(j<haystack.size()){
            int m = 0;
            for(int k = i;k<=j;k++){
                if(haystack[k]!=needle[m]){
                    m = -1;
                    break;
                }
                m++;
            }
            if(m==-1){
                j++;
                i++;
                continue;
            }
            return i;
        }
        return -1;
    }
};