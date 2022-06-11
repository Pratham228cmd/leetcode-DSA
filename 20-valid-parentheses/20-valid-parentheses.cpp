class Solution {
public:
    bool isValid(string s) {
         int n=s.size();
        stack<char>st;
        char x;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(st.empty())return false;
            else{
                x=s[i];
                if(x=='}' and st.top()=='{')st.pop();
               else if(x==')' and st.top()=='(')st.pop();
                else if(x==']' and st.top()=='[')st.pop();
                else return false;
            }
        }
        if(st.empty()==0)return false;
        return true;
    }
};