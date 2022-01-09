class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        int hold=-arr[0];
        int empty=0;
        for(int i=1;i<n;i++){
            hold=max(hold,-arr[i]+empty);
            empty=max(empty,hold+arr[i]-fee);
        }
        return empty;
    }
};