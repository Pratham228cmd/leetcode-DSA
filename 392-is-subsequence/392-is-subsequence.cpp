class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n= t.length();
        int m= s.length();
        int pos=0;
        for(int i=0;i<n&&pos<m;i++){
            if(s[pos]==t[i])
                pos++;
        }
        return m==pos;
    }
};