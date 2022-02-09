class Solution {
public:
    bool helper(int x){
        if(x==1)return 1;
        if(x%3!=0)return 0;
        return helper(x/3);
    }
    bool isPowerOfThree(int n) {
        if(n==0)return false;
        return helper(n);
    }
};