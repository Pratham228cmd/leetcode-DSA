class Solution {
public:
    bool check(vector<vector<char>>& board,int val,int x,int y){
        for(int i=0;i<=8;i++){
            if(i==y)continue;
            if(board[x][i]==val)return false;
        }
        for(int i=0;i<9;i++){
            if(i==x)continue;
            if(board[i][y]==val)return false;
        }
        for(int i=3*(x/3);i<3*(x/3)+3;i++){
            for(int j=3*(y/3);j<3*(y/3)+3;j++){
                if(board[i][j]==val and i!=x and j!=y)return false; 
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                else{
                    if(check(board,board[i][j],i,j)==false)
                        return false;
                }
            }
        }
        return true;
        
    }
};