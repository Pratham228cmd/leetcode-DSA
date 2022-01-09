class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==1)return 1;
        int res=INT_MIN;
        sort(pairs.begin(),pairs.end(),cmp);
        // sort(pairs.begin(),pairs.end(),comp);
        int cnt=1;
        int temp=pairs[0][1];
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i][0] > temp)
            {
                temp=pairs[i][1];
                cnt++;
            }
        }
        return cnt;
        
    }
};