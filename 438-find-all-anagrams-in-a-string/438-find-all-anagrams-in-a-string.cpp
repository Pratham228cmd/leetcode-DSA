class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
      vector<int> mpp(26,0);
        vector<int>mps(26,0);
        if(m>n)return {};
        vector<int>res;
        for(int i=0;i<m;i++){
            mps[s[i]-'a']++;
            mpp[p[i]-'a']++;
        }
        if(mpp==mps)res.push_back(0);
        for(int i=m;i<n;i++){
            mps[s[i-m]-'a']--;
            mps[s[i]-'a']++;
            if(mps==mpp){
                res.push_back(i-m+1);
            }
        }
        return res;
    }
};