const int m=1000000007;
class Solution {
public:
    int kadane(vector<int>& arr){
        int n=arr.size();
        long long sum=0;
        long long res=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>res)res=sum;
            if(sum<0)sum=0;
        }
        return res;
        
        
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        if(k==1){
            long long ans=kadane(arr);
            return ans;
        }
        else{
            if(sum<0){
                 for(int i=0;i<n;i++){
                arr.push_back(arr[i]);
            }
            long long ans=kadane(arr);
            return ans;
            }
            else{
                 for(int i=0;i<n;i++){
                arr.push_back(arr[i]);
            }
                long long ans=(kadane(arr)%m+((k-2)*sum)%m)%m;
            return ans;
            }
        }
    }
};