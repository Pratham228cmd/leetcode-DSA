class Solution {
public:
    
    bool check(int n,int i,int j,vector<vector<char>>&board){
        for(int c=0;c<j;c++){
            if(board[i][c]=='Q')
                return false;
        }
        for(int r=0;r<i;r++){
            if(board[r][j]=='Q')
                return false;
        }
         int x=i,y=j;
        while(x>=0 and y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            x--;
            y--;
        }
          x=i,y=j;
        while(x>=0 and y<n)
        {
            if(board[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        return true;
    }
    void solve(vector<vector<char>>&board,int n,int currow,vector<vector<string>>&res){
        if(currow==n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string str(board[i].begin(),board[i].end());
                temp.push_back(str);
            }
            res.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(n,currow,i,board)==true){
                board[currow][i]='Q';
                solve(board,n,currow+1,res);
                board[currow][i]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
         vector<vector<char>> board(n, vector<char> (n, '.')); 
       
        solve(board,n,0,res);
        return res;
    }
};