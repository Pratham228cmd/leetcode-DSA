// typedef pair<int,<pair<int,int>>> pi;
typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],{i,0}});
        }
        int res;
        while(k--){
            auto temp=pq.top();
            res=temp.first;
            int f=temp.second.first;
            int s=temp.second.second;
            pq.pop();
            if(s!=n-1){
                pq.push({matrix[f][s+1],{f,s+1}});
            }
        }
        return res;
    }
};