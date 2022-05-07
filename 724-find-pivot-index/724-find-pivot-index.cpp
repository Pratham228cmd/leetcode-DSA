class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n=arr.size();
        int sum=0,left=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        for(int i=0;i<n;i++){
            sum-=arr[i];
            if(sum==left)return i;
            left+=arr[i];
        }
        return -1;
    }
};