class Solution {
public:
    bool isvalid(string &s,int len,int indx){
        if(len+indx>s.size())return false;
        string temp=s.substr(indx,len);
        if(temp.size()>1 and temp[0]=='0')return false;
        int num=stoi(temp);
        if(num>255)return false;
        return true;
        
        
    }
    void helper(int indx,vector<string>&res,string ans,int cnt,string s){
       if(cnt==4 and s.size()==indx){
           string temp=ans.substr(0,ans.size()-1);
           res.push_back(temp);
           return;
       } 
        for(int i=1;i<=3;i++){
            if(isvalid(s,i,indx))
                helper(indx+i,res,ans+s.substr(indx,i)+".",cnt+1,s);
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
         if (s.size() > 12) return {};
        vector<string>res;
        string temp="";
        helper(0,res,temp,0,s);
        return res;
        
    }
};