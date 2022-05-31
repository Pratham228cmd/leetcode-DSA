class Solution {
public:
    bool helper(vector<int>& jobs, int k,int indx,int mid,vector<int>&sum){
        if(indx>jobs.size())return false;
        if(indx==jobs.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            sum[i]+=jobs[indx];
            if(sum[i]<=mid and helper(jobs,k,indx+1,mid,sum)){
                return true;
                
            }
            sum[i]-=jobs[indx];
            if(sum[i]==0)return false;
        }
        return false;
        
    }
    int minimumTimeRequired(vector<int>& nums, int k) {
         int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        // sort(nums.begin(),nums.end());
        int ans=-1;
        while(r>=l){
            int mid=(l+r)/2;
            vector<int>sum(k,0);
            if(helper(nums,k,0,mid,sum)){
                ans=mid;
                
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};