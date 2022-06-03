class Solution {
public:
    char maxfreq( vector<int>freq){
        int maxi=INT_MIN;
        char ans;
        for(int i=0;i<26;i++){
            if(freq[i]>maxi){
                maxi=freq[i];
                ans='a'+i;
            }
        }
        return ans;
    }
    string reorganizeString(string s) {
        int n=s.size();
        
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        char maxi=maxfreq(freq);
        string res(n, ' ');
        int indx=0;
        int cnt=freq[maxi-'a'];
        if(cnt>(n+1)/2)return "";
        while(cnt--){
            res[indx]=maxi;
            indx+=2;
        }
        freq[maxi-'a']=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0)continue;
            while(freq[i]){
                indx=(indx>=n)?1:indx;
                res[indx]=i+'a';
                indx+=2;
                freq[i]--;
            }
        }
        return res;
    }
};