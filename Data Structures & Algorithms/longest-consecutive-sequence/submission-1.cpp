class Solution {
public:
    int longestConsecutive(vector<int> &nums)
{
  set<int> st(nums.begin(), nums.end());
  auto it = st.begin();
  int count = 0, num = *it, temp = 1;
  if (st.size() == 0)
  {
    return 0;
  }
  it++;
  while (it != st.end())
  {
    if (num + 1 == *it)
    {
      temp++;
    }
    else
    {
      count = max(count, temp);
      temp = 1;
    }
    num = *it;
    ++it;
  }
  return max(count, temp);
}
};
