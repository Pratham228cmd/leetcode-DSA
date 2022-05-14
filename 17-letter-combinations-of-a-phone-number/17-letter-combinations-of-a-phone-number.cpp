class Solution {
public:
    vector<string>res;
    void helper(int indx,string temp,string digits,vector<string>chars){
        if(indx==digits.size()){
            res.push_back(temp);
            return;
        }
        
        // for(int i=indx;i<)
        int x=digits[indx]-'0';
        for(auto ch:chars[x]){
            helper(indx+1,temp+ch,digits,chars);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        // vector<string>chars={"0","1","abc","def","ghi","jkl"."mno","pqrs","tuv","wxyz"};
        string temp;
         vector<string> chars = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        helper(0,temp,digits,chars);
        return res;
    }
    
};