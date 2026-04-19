class Solution {
public:
 bool checkRow(vector<vector<char>>& board){
    for(int i = 0;i<9;i++){
        vector<bool> arr(10,false);
        for(int j = 0;j<9;j++){
            if(board[i][j]=='.') {
                continue;
            }
            else if(arr[board[i][j]-'0']){
                return false;
            }

            arr[board[i][j]-'0'] = true;
        }
    }
    return true;
}
bool checkColumn(vector<vector<char>>& board){
    for(int j = 0;j<9;j++){
        vector<bool> arr(10,false);
        for(int i = 0;i<9;i++){
            if(board[i][j]=='.')
                continue;
            else if(arr[board[i][j]-'0']){
                return false;
            }
            arr[board[i][j]-'0'] = true;
        }
    }
    return true;
}

bool check3x3(vector<vector<char>>& board){
    for(int boxi = 0;boxi<board.size();boxi+=3){
        for(int boxj = 0;boxj<board.size();boxj+=3) {
            vector<bool> arr(10,false);
            for(int i = boxi;i<boxi+3;i++){
                for(int j = boxj;j<boxj+3;j++){
                    if(board[i][j]=='.')
                        continue;
                    else if(arr[board[i][j]-'0']){
                        return false;
                    }
                    arr[board[i][j]-'0'] = true;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    return checkRow(board)&& checkColumn(board)&&check3x3(board);
}
};