class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)mp[arr[i]]++;
        priority_queue<pair<int,int>>pq;
        // for(int i=0;i<n;i++)pq.insert(mp[arr[i]])
        for(auto it:mp)pq.push({it.second,it.first});
        vector<int>res;
        for(int i=0;i<k and pq.size();i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};