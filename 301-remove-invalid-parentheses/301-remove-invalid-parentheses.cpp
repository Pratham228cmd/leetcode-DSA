class Solution {
public:
    vector<string>res;
    unordered_set<string> uset; 
    int minremoval(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(')');
                }
                else if(st.top()==')'){
                    st.push(')');
                }
                else if(st.top()=='('){
                    st.pop();
                }
            }
        }
        
        int invalid=st.size(); //minimum removals
        
        return invalid;
    }
    void helper(string s,int invalid){
        if(invalid==0){
            int x=minremoval(s);
            if(x==0)res.push_back(s);
            return;
        }
        if(invalid<0)return;
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' and s[i]!=')')continue;
             string left=s.substr(0,i);
          string right=s.substr(i+1);
          string temp=left+right;
             if(uset.find(temp)==uset.end()){
                 uset.insert(temp);
                 helper(temp,invalid-1);
             }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int x=minremoval(s);
        helper(s,x);
        return res;
        
    }
};