class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
      int maxlen=1;
        int l,h,start=0,end;
        for(int i=1;i<n;i++){
            l=i-1,h=i;   //even
            while(l>=0 and h<n and s[l]==s[h]){
                if(h-l+1>maxlen){
                    start=l;
                    maxlen=h-l+1;
                }
                l--,h++;
            }
             l=i-1,h=i+1;   //odd
            while(l>=0 and h<n and s[l]==s[h]){
                if(h-l+1>maxlen){
                    start=l;
                    maxlen=h-l+1;
                }
                l--,h++;
            }
        }
        return s.substr(start,maxlen);
    }
};