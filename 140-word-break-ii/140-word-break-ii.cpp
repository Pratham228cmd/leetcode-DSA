class Solution {
public:
    vector<string>res;
    void helper(string s,int ind,string temp,unordered_set<string> st){
        if(ind==s.size()){
            temp.pop_back();
            
            res.push_back(temp);
            return;
        }
        string str="";
        for(int i=ind;i<s.size();i++){
            str+=s[i];
            if(st.count(str)){
                helper(s,i+1,temp+str+" ",st);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> set;
        // vector<string> res;
        for(auto word:wordDict)
            set.insert(word);
        //to store the current string 
        string curr="";
        helper(s,0,curr,set);
        return res;
    }
};