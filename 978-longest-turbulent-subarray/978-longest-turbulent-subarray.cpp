class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()<=1) {
            return arr.size();
        }
        int n=arr.size();
         int inc = 1; int dec = 1; int maxi = 1;
        // vector<int>dp(arr.size());
        // dp[0]=1;
        // dp[1]=(arr[1]==arr[0])?1:2;
        // int ans=max(dp[0],dp[1]);
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                inc=dec+1;
                dec=1;
            }
            else if(arr[i+1]>arr[i]){
                dec=inc+1;
                inc=1;
            }
            else inc=dec=1;
            
            maxi=max(maxi,max(inc,dec));
        }
        return maxi;
        
        
        
        
        
    }
};