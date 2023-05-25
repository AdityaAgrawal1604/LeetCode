class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    
    int k;
    
    bool isSafe(int row,int col,vector<bool> &rows,vector<bool> &ld, vector<bool> &rd){
        if(rows[row]||ld[row+col]||rd[col-row+k-1]){
            return false;
        }
        return true;
    }
    void solve(int col,vector<bool> &rows,vector<bool> &ld,vector<bool> &rd){
        if(col==k){
            ans.push_back(board);
            return;
        }
        for(int i = 0;i<k;i++){
            if(isSafe(i,col,rows,ld,rd)){
                rows[i]=true;
                ld[i+col]=true;
                rd[col-i+k-1]=true;
                board[i][col]='Q';
                solve(col+1,rows,ld,rd);
                rows[i]=false;
                ld[i+col]=false;
                rd[col-i+k-1]=false;
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        k = n;
        string s(k,'.');
        for(int i = 0;i<k;i++){
            board.push_back(s);
        }
        vector<bool> rows(k,false),ld(2*k-1,false),rd(2*k-1,false);
        solve(0,rows,ld,rd);
        return ans;
    }
};