class Solution {
public:
   static bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int res=1;
        int prev=0;
        for(int i=1;i<points.size();i++){
            if(points[prev][1]<points[i][0]){res++;
            prev=i;}
            // else if()
        }
        return res;
    }
};