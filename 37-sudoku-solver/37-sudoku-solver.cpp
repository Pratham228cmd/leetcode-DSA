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
    bool helper(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(check(board,c,i,j)){
                            board[i][j]=c;
                            if(helper(board))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};