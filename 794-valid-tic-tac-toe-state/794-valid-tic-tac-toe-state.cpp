class Solution {
public:
    int nox=0,noo=0;
    bool helper(vector<string>& board,char ch){
        for(int i=0;i<3;i++){
            if(board[i][0]==ch and board[i][0]==board[i][1] and board[i][1]==board[i][2])
                return true;
        
         else if(board[0][i] == ch && \
                    (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            {
                return true;
            }}
     if(board[0][0] == ch && \
           board[1][1] == board[0][0] && board[2][2] == board[0][0])
        {
            return true;
        }
        else if(board[0][2] == ch && \
           board[1][1] == board[0][2] && board[2][0] == board[0][2])
        {
            return true;
        }
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='X')nox++;
                else if(board[i][j]=='O')noo++;
            }
        }
        if(!(nox == noo || nox == noo + 1)) return false;
        if(noo==nox){
            return !(helper(board,'X'));
        }
        else{
            return !(helper(board,'O'));
        }
        return true;
    }
};