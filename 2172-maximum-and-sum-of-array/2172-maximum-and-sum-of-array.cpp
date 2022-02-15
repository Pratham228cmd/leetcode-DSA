class Solution {
public:
    int maximumANDSum(vector<int>& A, int numSlots) {
        A.resize(2 * numSlots); // append 0s to make sure the length of `A` is `2 * numSlots`
        int N = A.size();
        vector<int> dp(1 << N);
        for (int m = 1; m < 1 << N; ++m) {
            int cnt = __builtin_popcount(m), slot = (cnt + 1) / 2; 
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) { // we assign A[i] to `slot`-th slot
                    dp[m] = max(dp[m], dp[m ^ (1 << i)] + (slot & A[i]));
                }
            }
        }
        return dp[(1 << N) - 1];
        
    }
};