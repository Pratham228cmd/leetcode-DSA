class Solution {
public:
    int m,n;
    void helper(int i,int j,vector<vector<char>>& board){
         if(i<0 or j<0 or i>=m or j>=n or board[i][j] != 'O') return;
         board[i][j] = '#';
        helper(i+1,j,board);
        helper(i,j+1,board);
        helper(i-1,j,board);
        helper(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                helper(i,0,board);
            if(board[i][n-1]=='O')
                helper(i,n-1,board);
        }
        for(int j=0;j<n;j++){
             if(board[0][j] == 'O')
                 helper(0,j,board);
            if(board[m-1][j]=='O')
                helper(m-1,j,board);
        }
         for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
        
        
        
    }
};