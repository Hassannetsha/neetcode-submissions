class Solution {
public:
    bool check_columns(vector<vector<char>> &board)
{
  for (int i = 0; i < board.size(); i++)
  {
    set<char> st;
    for (int j = 0; j < board[i].size(); j++)
    {
      if ((st.empty() || !st.count(board[j][i])) && board[j][i] != '.')
      {
        st.insert(board[j][i]);
      }
      else if (board[j][i] != '.')
      {
        return false;
      }
    }
  }
  return true;
}
bool check_rows(vector<vector<char>> &board)
{
  for (int i = 0; i < board.size(); i++)
  {
    set<int> st;
    for (int j = 0; j < board[i].size(); j++)
    {
      if ((st.empty() || !st.count(board[i][j])) && board[i][j] != '.')
      {
        st.insert(board[i][j]);
      }
      else if (board[i][j] != '.')
      {
        return false;
      }
    }
  }
  return true;
}
bool check_squares(vector<vector<char>> &board)
{
  for (int i = 0; i < board.size(); i += 3)
  {
    for (int j = 0; j < board[i].size(); j += 3)
    {
      set<int> st;
      for (int k = i; k < i + 3; k++)
      {
        for (int l = j; l < j + 3; l++)
        {
          if ((st.empty() || !st.count(board[k][l]) && board[k][l] != '.'))
          {
            st.insert(board[k][l]);
          }
          else if (board[k][l] != '.')
          {
            return false;
          }
        }
      }
    }
  }
  return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
  return check_columns(board) && check_rows(board) && check_squares(board);
}
};
