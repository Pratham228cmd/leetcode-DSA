class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int buy=-arr[0];
        int sell=0;
        int cool=0;
        for(int i=1;i<n;i++){
            int nextbuy=max(cool-arr[i],buy);
            int nextsell=max(sell,buy+arr[i]);
            int nxtcool=max(cool,sell);
            buy=nextbuy;
            sell=nextsell;
            cool=nxtcool;
            
        }
        return sell;
        
    }
};