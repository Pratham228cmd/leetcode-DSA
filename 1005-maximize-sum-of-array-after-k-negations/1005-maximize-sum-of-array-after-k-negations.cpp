class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        int sum=0;
        while(k--){
            int x=pq.top();
            pq.pop();
            x=-1*x;
            pq.push(x);
        }
        for(int i=0;i<n;i++)
        {
            int x=pq.top();
            sum+=x;
            pq.pop();
        }
        return sum;
        
        
    }
};