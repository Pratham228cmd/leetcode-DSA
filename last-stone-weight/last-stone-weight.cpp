class Solution {
public:
    int lastStoneWeight(vector<int>&arr) {
        int n=arr.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)pq.push(arr[i]);
        while(pq.size()!=2){
            if(pq.size()==1)break;
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            pq.push(x-y);
        }
        if(pq.size()==2){
              int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            return x-y;
        }
        else return pq.top();
    }
};