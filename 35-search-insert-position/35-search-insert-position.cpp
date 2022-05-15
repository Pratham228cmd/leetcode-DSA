class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=n-1;
        int ans=n;
        if(arr[0]>target)return 0;
        while(r>=l){
            int mid=(l+r)/2;
            if(arr[mid]==target)return mid;
           else if(arr[mid]<target){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        
        return ans+1;
    }
};