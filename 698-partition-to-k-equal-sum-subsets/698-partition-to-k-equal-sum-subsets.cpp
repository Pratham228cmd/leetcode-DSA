class Solution {
public:
    vector<int>visited;
    int target;
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
        if(k==1){
            return true;
        }
		sum = accumulate(nums.begin(), nums.end(), sum);
		if(nums.size()<k || sum%k)return false;

        sort(nums.begin(),nums.end());
        target=sum/k;
		visited.resize(nums.size(),false);
		return backtrack(nums, 0, 0, k);
	}

	bool backtrack(vector<int>& nums, int curr_sum, int i, int k) {
        
        if(k==0){
            return true;
        }
        if (curr_sum == target) 
            return backtrack(nums, 0, 0, k-1);
        
    
	
		for (int j = i; j < nums.size(); j++) 
        {
			if (!visited[j] && curr_sum + nums[j] <= target)
            {
                
                    visited[j] = true;
			        if (backtrack(nums, curr_sum + nums[j], j+1, k)) 
                        return true;
			        visited[j] = false;

                if(!curr_sum || curr_sum+nums[i]==target)
                    return false;

            }	
        }
		return false;
	}
};