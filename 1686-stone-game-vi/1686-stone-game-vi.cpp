class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
         priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<aliceValues.size();i++){
            pq.push({bobValues[i]+aliceValues[i],{aliceValues[i],bobValues[i]}});
        }
        int a=0,b=0;
        int i=0;
        while(!pq.empty()){
            if(i%2==0){
                a+=pq.top().second.first;
                pq.pop();
            }
            else{
                b+=pq.top().second.second;
                pq.pop();
            }
            i++;
        }
        if(a>b)return 1;
        if(b>a)return -1;
        else return 0;
        
        
        
    }
};