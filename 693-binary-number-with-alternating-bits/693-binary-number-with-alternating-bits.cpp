class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i=(n&1);
        while(n>0){
            if((n&1)==i){
                i=1-i;
                n=n>>1;
            }
            else return 0;
            
        }
        return 1;
    }
};